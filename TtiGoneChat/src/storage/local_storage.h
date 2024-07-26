#ifndef LOCAL_STORAGE_H
#define LOCAL_STORAGE_H

namespace Storage
{
void InitaLoadTheme();
void start();
void writeSettings();
void rewriteSettingsIfNeeded();
void readLangPack();

} // namespace Storage

#endif // LOCAL_STORAGE_H