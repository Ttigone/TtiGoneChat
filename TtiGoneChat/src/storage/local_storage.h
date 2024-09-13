#ifndef LOCAL_STORAGE_H
#define LOCAL_STORAGE_H

#include "storage/storage_databases.h"


namespace Storage
{

void start();


void LoadConfigFile();

void InitialLoadTheme();

void writeSettings();

void rewriteSettingsIfNeeded();

void readLangPack();


bool ApplyDefaultNightMode();


DatabaseConfig readDatabaseConfig(const QString& file_path); 

void ReadDataBaseConfig();

} // namespace Storage

#endif // LOCAL_STORAGE_H