#ifndef SETTINGS_H
#define SETTINGS_H

#include "base/integration.h"

/// 定义宏 接受 2 个参数
/// 声明一个外部全局变量 extern 关键字用于声明在另一个文件中定义的变量 新的名字是 gName
/// 声明一个内联函数，返回对前面声明的全局变量的引用。 函数的名称是 cName
/// --- example
/// DeclareReadSetting(int, Setting)
/// 等效于
/// extern int Setting
/// inline const int &cSetting() {
///     return gSetting;
/// }
#define DeclareReadSetting(Type, Name) extern Type g##Name; \
inline const Type &c##Name() { \
        return g##Name; \
}

/// 定义宏 接受 2 个参数
/// 在 DeclarReadSetting 的基础上，添加 Setting 函数
#define DeclareSetting(Type, Name) DeclareReadSetting(Type, Name) \
inline void cSet##Name(const Type &Name) { \
        g##Name = Name; \
}

/// 引用函数
#define DeclareRefSetting(Type, Name) DeclareSetting(Type, Name) \
inline Type &cRef##Name() { \
        return g##Name; \
}

enum LaunchMode {
    LaunchModeNormal = 0,
    LaunchModeAutoStart,
    LaunchModeFixPrevious,
    LaunchModeCleanup,
};




#endif // SETTINGS_H
