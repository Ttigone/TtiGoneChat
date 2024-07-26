#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QWidget>
// #include "ui/widgets/fields/auto_complete_input_field.h"

#include "qt-material/components/qtmaterialautocomplete.h"
#include "qt-material/components/qtmaterialraisedbutton.h"
#include "base/basic_types.h"

QT_BEGIN_NAMESPACE

class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QPushButton;

QT_END_NAMESPACE

namespace Ui {

// class AutocompleteInputField;

} // namespace Ui


namespace Window {

class Launcher : public QWidget
{
    // Q_OBJECT
public:
    explicit Launcher(QWidget *parent = nullptr);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    // 屏蔽 移动窗口事件
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void init();
    void loadStyleSheet(Theme theme);

private:
    // Theme1 currentTheme;
    qreal global_Px_;
    qreal global_Py_;
    qreal del_Px_;
    qreal del_Py_;
    qreal click_Px_;
    qreal click_Py_;
    bool is_drag_;


    QVBoxLayout *layout_;
    QHBoxLayout *titlebar_layout_;

    QWidget *titlebar_;
    QPushButton *icon_label_;
    QPushButton *min_btn_;
    QPushButton *close_btn_;
    QPushButton *max_btn_;

    QLabel *img_label_;
    QtMaterialTextField *usr_line_edit_;
	QtMaterialTextField *pwd_line_edit_;

	QtMaterialRaisedButton *login_btn_;
	QtMaterialRaisedButton *switch_user_btn_;

    Theme current_theme;
};

} // namespace Window


#endif // LAUNCHER_H
