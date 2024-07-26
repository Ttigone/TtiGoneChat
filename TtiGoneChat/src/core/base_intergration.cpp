#include "base_intergration.h"

namespace Core {

BaseIntergration::BaseIntergration(int argc, char *argv[])
    : Integration(argc, argv)
{

}

bool BaseIntergration::logSkipDebug()
{
	return true;
}

void BaseIntergration::logMessageDebug(const QString &message)
{

}

void BaseIntergration::logMessage(const QString &message)
{

}


} // namespace Core
