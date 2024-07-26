#include "core/launcher.h"

int main(int argc, char *argv[]) {
  // µ¥Àý¹¹Ôì
  const auto launcher = Core::Launcher::Create(argc, argv);
  return launcher ? launcher->exec() : 1;
}
