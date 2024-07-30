#include "base/integration.h"

#include <QFileInfo>
#include <QDir>

namespace base {

namespace {

Integration *IntegrationInstance = nullptr;

} // namespace


void Integration::Set(Integration *instance) {
    IntegrationInstance = instance;
}

Integration &Integration::Instance() {
    return *IntegrationInstance;
}

bool Integration::Exists() {
    return (IntegrationInstance != nullptr);
}

Integration::Integration(int argc, char *argv[]) {}

void Integration::logAssertionViolation(const QString &info)
{

}
    // const auto path =
}

