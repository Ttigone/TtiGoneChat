#ifndef INTEGRATION_H
#define INTEGRATION_H

#include "base/basic_types.h"

// BUG  String
namespace base {

class Integration
{
public:

    static void Set(Integration *instance);
    static Integration &Instance();
    static bool Exists();

    Integration(int argc, char *argv[]);
    virtual ~Integration() = default;

    virtual bool logSkipDebug() = 0;
    virtual void logMessageDebug(const QString &message) = 0;
    virtual void logMessage(const QString &message) = 0;
    virtual void logAssertionViolation(const QString &info);


private:
    QString executable_dir_;
    QString executable_name_;
};

} // namespace base


#endif // INTEGRATION_H
