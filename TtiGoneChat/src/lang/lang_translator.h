#ifndef LANG_TRANSLATOR_H
#define LANG_TRANSLATOR_H

#include <QTranslator>

namespace Lang
{
	
class Translator : public QTranslator
{
public:
    /// @brief 重载翻译函数
    /// @param context 
    /// @param source_text 
    /// @param disambiguation 
    /// @param n 
    /// @return 
    QString translate(const char *context, const char *source_text, const char *disambiguation = 0, int n = -1) const override;
};
}


#endif // LANG_TRANSLATOR_H
