#include "launcher.h"
#include "sandbox.h"


#include <QLoggingCategory>
#include <QStandardPaths>
#include <QDir>
#include <QApplication>
#include <QString>


namespace Core {

namespace {

uint64 InstallationTag = 0;

///
/// @brief The FilteredCommandLineArguments class
/// 分析命令行参数
//class FilteredCommandLineArguments {
// public:
//  FilteredCommandLineArguments(int argc, char **argv);
//
//  int &count();
//  char **values();
//
// private:
//  static constexpr auto kForwardArgumentCount = 1;
//
//  int count_ = 0;
//  std::vector<QByteArray> owned_;
//  std::vector<char *> arguments_;
//
//  void pushArgument(const char *text);
//};

}  // namespace

//FilteredCommandLineArguments::FilteredCommandLineArguments(int argc,
//                                                           char **argv) {
//  for (auto i = 0; i != kForwardArgumentCount; ++i) {
//    // 存放
//    pushArgument(argv[i]);
//  }
//
//  // 尾部标志
//  pushArgument(nullptr);
//}
//
//int &FilteredCommandLineArguments::count() {
//  count_ = arguments_.size() - 1;
//  return count_;
//}
//
//char **FilteredCommandLineArguments::values() { return arguments_.data(); }
//
//void FilteredCommandLineArguments::pushArgument(const char *text) {
//  owned_.emplace_back(text);
//  arguments_.push_back(owned_.back().data());
//}

const char kOptionFractionalScalingEnabled[] = "fractional-scaling-enabled";
const char kOptionFreeType[] = "freetype";

Launcher *Launcher::InstanceSetter::Instance = nullptr;
//std::unique_ptr<Launcher> Launcher::instance_ = nullptr;
int Launcher::argc_ = 0;
char **Launcher::argv_ = nullptr;

//Launcher::Launcher(int argc, char *argv[])
//    : argc_(argc),
//      argv_(argv),
//      arguments_(readArguments(argc_, argv_)),
//      base_integration_(argc_, argv_),
//      initial_working_dir_(QDir::currentPath() + '/') {
//  base::Integration::Set(&base_integration_);
//}


Launcher::Launcher(int argc, char *argv[])
    :
	//arguments_(readArguments(argc, argv)),
      //base_integration_(argc_, argv_),
      initial_working_dir_(QDir::currentPath() + '/') {
  //base::Integration::Set(&base_integration_);
  Initialize(argc, argv);
}

// 另一个线程访问时，可能已经是 空指针
Launcher::~Launcher()
{
	InstanceSetter::Instance = nullptr;
}

std::unique_ptr<Launcher> Launcher::Create(int argc, char *argv[]) {
  return std::make_unique<Launcher>(argc, argv);
  //return std::unique_ptr<Launcher>(new Launcher(argc, argv));
}

int Launcher::exec() {
  init();
  initHighDpi();

  // 执行程序
  // 执行了 sandBox::exec() 清理任务 ? 可是返回结果 是 0, 代表成功
  auto result = executeApplication();

  //qDebug() << "result : " << result;

  return result;
}

//const QStringList &Launcher::arguments() const
//{
//	//return arguments_;
//}

QString Launcher::initialWorkingDir() const { return initial_working_dir_; }

bool Launcher::customWorkingDir() const {
  return custom_working_dir_.isEmpty();
}

uint64 Launcher::installationTag() const { return InstallationTag; }

bool Launcher::checkPortableVersionFolder() { return true; }

bool Launcher::validateCustomWorkingDir() { return true; }

void Launcher::workingFolderReady() {}

void Launcher::writeDebugModeSetting() {}

void Launcher::writeInstallBetaVersionsSetting() {}

void Launcher::prepareSettings() {}

void Launcher::initQtMessageLogging() {}

void Launcher::processArguments() {}

//QStringList Launcher::readArguments(int argc, char *argv[]) const {
//  assert(argc >= 0);
//
//  if (const auto native = readArgumentsHook(argc, argv)) {
//    return *native;
//  }
//}

void Launcher::init() {
  prepareSettings();
  initQtMessageLogging();

  QApplication::setApplicationName(u"TtiGoneChat"_q);

  initHook();
}

void Launcher::initHighDpi() {
#if QT_VERSION < QT_VERSION_CHECK(6, 2, 0)
  qputenv("QT_DPI_ADJUSTMENT_POLICY", "AdjustDpi");
#endif

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);
#endif

#ifdef WIN32
  QApplication::setHighDpiScaleFactorRoundingPolicy(
      Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
}

int Launcher::executeApplication() {
  // 解析参数
  //FilteredCommandLineArguments arguments(argc_, argv_);
  // 创建沙盒, 程序运行在沙盒中
  //SandBox sand_box(arguments.count(), arguments.values());
  SandBox sand_box(argc_, argv_);

  // 沙盒
  return sand_box.start();
}

}  // namespace Core
