#include "window/themes/window_theme.h"

#include <QFile>
#include <QDebug>

#include "base/debug_log.h"

//Log
namespace Window {

namespace Theme {

QByteArray readThemeContent(const QString& path) {
  QFile qss(path);
  if (!qss.exists())
  {
    LOG_ERROR() << "file not exist";
    return QByteArray();
  }
  if (!qss.open(QIODevice::ReadOnly | QIODevice::Text)) {
    // setStyleSheet(QString::fromUtf8(qss.readAll()));
    LOG_ERROR() << "open file failed";
    return QByteArray();
  }
  return qss.readAll();
}

QString NormalThemePath() { return QString(); }

bool isNormalMode() { return true; }

void SetNormalMode(bool normalMode) {}

QString NightThemePath() { return QString(); }

bool isNightMode() { return false; }

void SetNightMode(bool nightMode) {}

QByteArray LoadFromQss(const QString& path, QByteArray* out_content)
{
  const auto content = readThemeContent(path);
  //if *
  return content;
}

}  // namespace Theme

}  // namespace Window
