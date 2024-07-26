#ifndef SETTINGS_TYPE_H
#define SETTINGS_TYPE_H

#include <memory>

namespace Settings {

struct AbstractSectionFactory;
using Type = std::shared_ptr<AbstractSectionFactory>;

}  // namespace Settings

#endif // SETTINGS_TYPE_H