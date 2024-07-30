#ifndef LOCAL_STORAGE_H
#define LOCAL_STORAGE_H

namespace Storage
{

void start();

void LoadConfigFile();

void InitialLoadTheme();

void writeSettings();

void rewriteSettingsIfNeeded();

void readLangPack();


bool ApplyDefaultNightMode();


} // namespace Storage

#endif // LOCAL_STORAGE_H