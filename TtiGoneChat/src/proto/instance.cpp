
#include "proto/instance.h"
#include "proto/sender.h"
#include "config.h"

namespace Proto {

class Instance::InstancePrivate : private Sender {
 public:
  InstancePrivate(Instance* instance, Instance::Mode mode, Fields&& fields);

  void start();

  [[nodiscard]] Config& config() const;
  [[nodiscard]] const ConfigFields& configValues() const;

 private:
  const Instance* instance_;
  const Instance::Mode mode_ = Instance::Mode::Normal;
  const std::unique_ptr<Config> config_;
};


Instance::Fields::Fields() = default;

Instance::Fields::Fields(Fields&& other) = default;

auto Instance::Fields::operator=(Fields&& other) -> Fields& = default;

Instance::Fields::~Fields() = default;

Instance::InstancePrivate::InstancePrivate(Instance* instance,
                                           Instance::Mode mode, Fields&& fields)
    : Sender(instance),
      instance_(instance),
      mode_(mode),
      config_(std::move(fields.config_)) {}

void Instance::InstancePrivate::start() {}

Config& Instance::InstancePrivate::config() const { return *config_; }

const ConfigFields& Instance::InstancePrivate::configValues() const {
  return config_->values();
}

Instance::Instance(Mode mode, Fields&& fields)
    : QObject(),
      d_private_(
          std::make_unique<InstancePrivate>(this, mode, std::move(fields))) {
  d_private_->start();
}


// Instance::Instance(const Instance& other) : QObject(), d_private_(std::make_unique<InstancePrivate>(*other.d_private_)) {}

Instance::~Instance() = default;

const ConfigFields& Instance::configValues() const {
  return d_private_->configValues();
}

const Config& Instance::config() const { return d_private_->config(); }



} // namespace Proto



