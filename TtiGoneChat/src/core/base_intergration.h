#ifndef BASE_INTERGRATION_H
#define BASE_INTERGRATION_H

#include "base/integration.h"

namespace Core {

class BaseIntergration final : public base::Integration
{
public:
    BaseIntergration(int argc, char *argv[]);

    bool logSkipDebug() override;
    void logMessageDebug(const QString &message) override;
    void logMessage(const QString &message) override;

};


} // namespace Core

#endif // BASE_INTERGRATION_H
