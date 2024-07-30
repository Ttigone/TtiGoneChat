#include "base/debug_log.h"

namespace base {

Logs& Logs::Instance()
{
	static Logs instance;
  return instance;
}

Logs::~Logs() {
  Logger::destroyInstance();
}

void Logs::setLoggingLevel(const Level& newLevel)
{
	Logger &logger = Logger::instance();
	logger.setLoggingLevel(newLevel);
}

void Logs::setDestIsFile(const QString& path, const int& maxSize,
                         const int& logCount) {
  Logger& logger = Logger::instance();
  DestinationPtr fileDestination(DestinationFactory::MakeFileDestination(
      path, EnableLogRotation, MaxSizeBytes(maxSize),
      MaxOldLogCount(logCount)));
  logger.addDestination(fileDestination);
}
	
void Logs::setDestIsCmd() {
  Logger& logger = Logger::instance();
  DestinationPtr debugDestination(
      DestinationFactory::MakeDebugOutputDestination());
  logger.addDestination(debugDestination);
}

Logs::Logs()
{
}
}  // namespace base