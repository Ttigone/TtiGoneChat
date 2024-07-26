#ifndef INSTANCE_H
#define INSTANCE_H

#include <QObject>

#include "local/session.h"

namespace Proto
{

class Config;
struct ConfigFields;

class Instance : public QObject {
  Q_OBJECT
 public:
  struct Fields;
  enum class Mode;

  Instance(Mode mode, Fields &&fields);
  Instance(const Instance &other);
  Instance &operator=(const Instance &other) = delete;
  ~Instance();

	[[nodiscard]] const ConfigFields &configValues() const;
	[[nodiscard]] const Config &config() const;


 private:
  struct Fields {
    Fields();
    Fields(Fields &&other);
    Fields &operator=(Fields &&other);
    ~Fields();

    std::unique_ptr<Config> config_;
  };
  enum class Mode { Normal, KeysDestroyer };
  
	class InstancePrivate;
  const std::unique_ptr<InstancePrivate> d_private_;

};

} // namespace Proto

#endif // INSTANCE_H