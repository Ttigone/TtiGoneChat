/*****************************************************************//**
 * \file   debug_log.h
 * \brief  Debug 日志文件
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H

#include <QsLog.h>

#define FILE_NAME __FILE__
#define LINE_COUNT __LINE__

#define LOG_TRACE() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::TraceLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::TraceLevel).stream()
#define LOG_DEBUG() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::DebugLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::DebugLevel).stream()
#define LOG_INFO()  \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::InfoLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::InfoLevel).stream()
#define LOG_WARN()  \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::WarnLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::WarnLevel).stream() << FILE_NAME << LINE_COUNT
#define LOG_ERROR() \
    if (QsLogging::Logger::instance().loggingLevel() > QsLogging::ErrorLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::ErrorLevel).stream()<<FILE_NAME<<LINE_COUNT 
#define LOG_FATAL() \
        if (QsLogging::Logger::instance().loggingLevel() > QsLogging::FatalLevel) {} \
    else QsLogging::Logger::Helper(QsLogging::FatalLevel).stream()<<FILE_NAME<<LINE_COUNT

namespace base {

using namespace QsLogging;

class Logs {
 public:
  static Logs &Instance();

  Logs(const Logs &other) = delete;
  Logs &operator=(const Logs &other) = delete;
  ~Logs();

  static void setLoggingLevel(const Level& newLevel);
  static void setDestIsFile(const QString& path, const int& maxSize, const int &logCount);
  static void setDestIsCmd();

private:
  Logs();
};

} // namespace base



#endif // DEBUG_LOG_H
