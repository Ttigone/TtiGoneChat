#include "lang/lang_translator.h"

#include "base/basic_types.h"

namespace Lang
{

QString Translator::translate(const char* context, const char* source_text, const char* disambiguation, int n) const
{
	// 重载了 ""_q 运算符
	if (u"QMenuBar"_q == context)
	{
		
		return QString();
	}
	if (u"QWidgetTextControl"_q == context || u"QLineEdit"_q == context) 
	{
		return QString();
	}
	if (u"QUnicodeControlCharacterMenu"_q == context)
	{
		return QString();
	}
	return QString();
}

} // namespace Lang
