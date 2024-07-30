#include "config.h"

#include "base/debug_log.h"


namespace Cfg {

int windowMinWidth;
int windowMinHeight;
int windowDefaultWidth;
int windowDefaultHeight;
int windowBigDefaultWidth;
int windowBigDefaultHeight;

void LoadConfig(const QString& filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    LOG_DEBUG() << "文件不存在";
    return;
  }
  // QByteArray fileData = file.readAll();
  // QJsonDocument jsonDoc(QJsonDocument::fromJson(fileData));
  // if (jsonDoc.isNull() || !jsonDoc.isObject()) {
  //   qWarning() << "无效的 JSON 配置文件:" << filePath;
  //   return;
  // }
  //   使用 QIODevice::map 来映射文件到内存，提高读取速度
  qint64 size = file.size();
  uchar* data = file.map(0, size);
  if (!data) {
    LOG_DEBUG() << "配置文件映射失败";
    return;
  }
  QJsonDocument jsonDoc = QJsonDocument::fromJson(
      QByteArray::fromRawData(reinterpret_cast<const char*>(data), size));
  file.unmap(data);  // 解除文件映射

  if (jsonDoc.isNull() || !jsonDoc.isObject()) {
    LOG_DEBUG() << "无效的 JSON 配置文件:" << "filePath";
    return;
  }

  QJsonObject jsonObj = jsonDoc.object();
  windowMinWidth = jsonObj["windowMinWidth"].toInt();
  windowMinHeight = jsonObj["windowMinHeight"].toInt();
  windowDefaultWidth = jsonObj["windowDefaultWidth"].toInt();
  windowDefaultHeight = jsonObj["windowDefaultHeight"].toInt();
  windowBigDefaultWidth = jsonObj["windowBigDefaultWidth"].toInt();
  windowBigDefaultHeight = jsonObj["windowBigDefaultHeight"].toInt();
}

}  // namespace Cfg
