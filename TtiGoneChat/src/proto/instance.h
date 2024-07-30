#ifndef INSTANCE_H
#define INSTANCE_H

#include <QObject>

#include "local/session.h"

namespace Proto
{

class Config;
struct ConfigFields;

// struct Fields;
// enum class Mode;

class Instance : public QObject {
  Q_OBJECT
 public:
  struct Fields {
  public:
    Fields();
    Fields(Fields &&other);
    Fields &operator=(Fields &&other);
    ~Fields();

    std::unique_ptr<Config> config_;
  };
  enum class Mode { Normal, KeysDestroyer };

  Instance(Mode mode, Fields &&field);

  Instance(const Instance &other) = delete;
  Instance &operator=(const Instance &other) = delete;
  ~Instance();

	[[nodiscard]] const ConfigFields &configValues() const;
	[[nodiscard]] const Config &config() const;

 private:
  class InstancePrivate;
  const std::unique_ptr<InstancePrivate> d_private_;

};

} // namespace Proto

#endif // INSTANCE_H
