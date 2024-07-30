/*****************************************************************//**
 * \file   window_theme.h
 * \brief  窗口主题
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/

#ifndef WINDOW_THEME_H
#define WINDOW_THEME_H

#include <QString>

namespace Window {
namespace Theme {

	
QByteArray readThemeContent(const QString& path);

/// @brief 获取主题路径
QString NormalThemePath();

/// @brief 正常模式
/// @return true: 成功 false: 失败
[[nodiscard]] bool isNormalMode();

/// @brief 设置普通模式
/// @param normal 
void SetNormalMode(bool normalMode);

/// @brief 获取主题路径
QString NightThemePath();

/// @brief 读取夜间模式
/// @return true: 成功 false: 失败
bool isNightMode();

/// @brief 设置夜间模式
/// @param nightMode 
void SetNightMode(bool nightMode);

QByteArray LoadFromQss(const QString &path, QByteArray *out_content);


}  // namespace Theme

}  // namespace Window

#endif  // WINDOW_THEME_H
