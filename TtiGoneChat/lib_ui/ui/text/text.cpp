#include "ui/text/text.h"


namespace Ui {

namespace Text {
void TString::setText(const QString& text, const TextParseOptions& options) {}

TextForMimeData TString::toTextForMimeData(TextSelection selection) const
{
  return toText(selection, true, true);

}

TextForMimeData TString::toText(TextSelection selection, bool composeExpanded, bool composeEntities) const
{
	return TextForMimeData();
}
}  // namespace Text
}  // namespace Ui
