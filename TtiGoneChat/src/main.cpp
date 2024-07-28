#include "core/launcher.h"

int main(int argc, char *argv[]) {
  // 单例构造
  const auto launcher = Core::Launcher::Create(argc, argv);
  return launcher ? launcher->exec() : 1;
}
