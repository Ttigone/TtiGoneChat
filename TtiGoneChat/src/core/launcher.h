#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "core/base_intergration.h"
#include <mutex>

namespace Core {

extern const char kOptionFractionalScalingEnabled[];
extern const char kOptionFreeType[];

class Launcher {
 public:
  Launcher(int argc, char *argv[]);
  virtual ~Launcher();

  Launcher(const Launcher &other) = delete;
  Launcher &operator=(const Launcher &other) = delete;

  static std::unique_ptr<Launcher> Create(int argc, char *argv[]);

  // 线程安全:
  //static Launcher &Instance() { return *InstanceSetter::Instance; }

  //static Launcher &Instance()
  //{
	 // static std::once_flag onceFlag;
  //  // lambda 表达式, 用于初始化 Instance
  //  std::call_once(onceFlag, [&]() {
		//		//InstanceSetter::Instance = new Launcher(0, nullptr);
  //    //Instance()
  //    //instance_.reset(new Launcher(argc_, argv_));
  //          instance_ = Create(argc_, argv_);
  //  });
  //  //return  *InstanceSetter::Instance;
  //  return *instance_.get();


  //}

  static Launcher &Instance()
  {
    return  *InstanceSetter::Instance;
  }

  static void Initialize(int argc, char *argv[]) {
    argc_ = argc;
    argv_ = argv;
  }

  ///
  /// @brief exec 阻塞
  /// @return
  ///
  virtual int exec();

  ///
  /// @brief arguments 返回输入参数列表
  /// @return
  ///
  //const QStringList &arguments() const;
  ///
  /// @brief initialWorkingDir 返回初始化工作文件夹
  /// @return
  ///
  QString initialWorkingDir() const;
  ///
  /// @brief customWorkingDir 传统工作文件夹
  /// @return
  ///
  bool customWorkingDir() const;
  ///
  /// @brief installationTag 安装标志
  /// @return
  ///
  uint64 installationTag() const;

  bool checkPortableVersionFolder();
  bool validateCustomWorkingDir();
  void workingFolderReady();
  void writeDebugModeSetting();
  void writeInstallBetaVersionsSetting();

 protected:
  enum class UpdateLaunch {
    // 准备更新
    PerformUpdate,
    // 立即重启
    JustRelaunch,
  };

 private:
  void prepareSettings();
  void initQtMessageLogging();
  void processArguments();

  //virtual std::optional<QStringList> readArgumentsHook(int argc,
  //                                                     char *argv[]) const {
  //  return std::nullopt;
  //}

  ///
  /// @brief readArguments 读取参数列表
  /// @param argc
  /// @param argv
  /// @return
  ///
  //QStringList readArguments(int argc, char *argv[]) const;
  void init();
  virtual void initHook() {}
  virtual void initHighDpi();

  // virtual bool launchUpdater(UpdateLaunch action) = 0;

  int executeApplication();

  struct InstanceSetter {
    InstanceSetter(Launcher *instance) { Instance = instance; }
    // 线程不安全， 多个线程同时尝试创建  Launcher 实例
    static Launcher *Instance;
  };

  InstanceSetter setter_ = {this};
  //static std::unique_ptr<Launcher> instance_;

  static int argc_;
  static char **argv_;
  //QStringList arguments_;
  //BaseIntergration base_integration_;

  QString initial_working_dir_;
  QString custom_working_dir_;
};

}  // namespace Core



#endif // LAUNCHER_H
