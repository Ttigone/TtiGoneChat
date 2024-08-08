#ifndef PROTO_CONFIG_H
#define PROTO_CONFIG_H

#include <QString>

namespace Proto {

/// <summary>
/// 配置字段
/// </summary>
struct ConfigFields {
  int chat_size_max_ = 200;
  int mega_group_size_max_ = 200;
  QString auto_login_token_;
};

  class Config final
  {
  public:
    explicit Config();
   Config(const Config &other);

    [[nodiscard]] const ConfigFields &values() const;
  private:
    ConfigFields fields_;
  };


} // namespace PROTO


#endif // PROTO_CONFIG_H
