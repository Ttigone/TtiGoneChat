/*****************************************************************//**
 * \file   completer_field.h
 * \brief  具有自动补全功能的编辑框
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef UI_WIDGETS_COMPLETER_FIELD_H
#define UI_WIDGETS_COMPLETER_FIELD_H

#include <ui/mb_widget.h>
#include <QVBoxLayout>

namespace Ui {
namespace Widgets {
class CustomizeFields;
} // namespace Widgets
} // namespace Ui

namespace Window {

class CompleterField : public Ui::MbWidget {
  Q_OBJECT
 public:
  CompleterField(QWidget *parent = nullptr);
  ~CompleterField();

  private:
  /// @brief 初始化操作
  void init();
  Ui::Widgets::CustomizeFields *customize_fields_;
  QVBoxLayout *layout_;
};

}  // namespace Window


#endif  // UI_WIDGETS_COMPLETER_FIELD_H
