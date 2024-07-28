/*****************************************************************//**
 * \file   config.h
 * \brief  读取配置信息
 * 
 * \author C3H3_Ttigone
 * \date   July 2024
 *********************************************************************/
#ifndef CONFIG_H
#define CONFIG_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

namespace Cfg {

extern int windowMinWidth;
extern int windowMinHeight;
extern int windowDefaultWidth;
extern int windowDefaultHeight;
extern int windowBigDefaultWidth;
extern int windowBigDefaultHeight;

void LoadConfig(const QString& filePath);

}  // namespace Cfg
#endif  // CONFIG_H
