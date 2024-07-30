#include "launcher.h"


#include "qt-material/components/qtmaterialtextfield.h"
 #include "qt-material/components/qtmaterialraisedbutton.h"

#include "windows.h"


#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QFile>
#include <QDir>

namespace Window {

Launcher::Launcher(QWidget *parent) {
  setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
  setFixedSize(420, 590);
  init();
  loadStyleSheet(Theme::day_custom);
}

void Launcher::mouseDoubleClickEvent(QMouseEvent *event) {}

void Launcher::mouseMoveEvent(QMouseEvent *event) {
  if (is_drag_) {
    event->ignore();
    return;
  }
  if (event->button() == Qt::LeftButton) {
    move(event->globalPosition().x() - click_Px_,
         event->globalPosition().y() - click_Py_);
    event->accept();
  }
}

void Launcher::mousePressEvent(QMouseEvent *event) {
  auto win_px = event->pos().x();
  auto win_py = event->pos().y();

  // Coordinates relative to the screen
  global_Px_ = event->globalPosition().x();
  global_Py_ = event->globalPosition().y();

  // Coordinates in the upper left corner of the window
  del_Px_ = global_Px_ - win_px;
  del_Py_ = global_Py_ - win_py;

  //
  click_Px_ = global_Px_ - del_Px_;
  click_Py_ = global_Py_ - del_Py_;
  if (event->button() == Qt::LeftButton) {
    ReleaseCapture();
    SendMessage(HWND(winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
    // SendMessage(HWND(winId()), WM_SYSCOMMAND,  HTCAPTION, 0);
  }
  event->accept();
}

void Launcher::mouseReleaseEvent(QMouseEvent *event) {
  is_drag_ = false;
  event->accept();
}

bool Launcher::eventFilter(QObject *watched, QEvent *event) {
  if (watched == icon_label_) {
    if (event->type() == QEvent::MouseButtonPress) {
      event->ignore();
      return true;

    } else {
      return false;
    }
  } else {
    return QWidget::eventFilter(watched, event);
  }
}

void Launcher::init() {
  titlebar_layout_ = new QHBoxLayout;
  layout_ = new QVBoxLayout(this);
  layout_->setSpacing(0);

  titlebar_ = new QWidget;
  titlebar_->setLayout(titlebar_layout_);
  titlebar_->setFixedHeight(30);

  icon_label_ = new QPushButton;
  icon_label_->setObjectName(QStringLiteral("Login-icon-button"));
  icon_label_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  icon_label_->setIconSize(QSize(25, 25));

  min_btn_ = new QPushButton;
  min_btn_->setObjectName(QStringLiteral("Login-min-button"));
  min_btn_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  // min_btn_->setIcon(QIcon(":/../icons/login/login_minimize.png"));

  close_btn_ = new QPushButton;
  close_btn_->setObjectName(QStringLiteral("Login-close-button"));
  close_btn_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  titlebar_layout_->addWidget(icon_label_);
  titlebar_layout_->addStretch();
  titlebar_layout_->addWidget(min_btn_);
  titlebar_layout_->addWidget(close_btn_);
  titlebar_layout_->setContentsMargins(QMargins());
  titlebar_layout_->setSpacing(0);

  usr_line_edit_ = new QtMaterialTextField;
  usr_line_edit_->setMaximumWidth(400);
  usr_line_edit_->setPlaceholderText(tr("user"));

  pwd_line_edit_ = new QtMaterialTextField;
  pwd_line_edit_->setMaximumWidth(400);
  pwd_line_edit_->setPlaceholderText(tr("pwd"));

  img_label_ = new QLabel();
  // img_label_->setPixmap(QPixmap::fromImage(QImage(":/resources/Icon/windowbar/app/chat.png")));
  img_label_->setMaximumSize(100, 100);

  login_btn_ = new QtMaterialRaisedButton(tr("sign up"));
  login_btn_->setObjectName(QStringLiteral("Login-login-button"));
  login_btn_->setMinimumSize(250, 30);
  login_btn_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  switch_user_btn_ = new QtMaterialRaisedButton(tr("switch"));
  switch_user_btn_->setObjectName(QStringLiteral("Login-switch_user-button"));
  switch_user_btn_->setMinimumSize(40, 30);
  switch_user_btn_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  // titlebar
  layout_->addWidget(titlebar_);

  QVBoxLayout *operator_layout = new QVBoxLayout;
  operator_layout->addSpacerItem(new QSpacerItem(0, 80));
  operator_layout->addWidget(img_label_, 0, Qt::AlignHCenter);

  // usr edit
  operator_layout->addSpacerItem(new QSpacerItem(0, 10));
  operator_layout->addWidget(usr_line_edit_, 0, Qt::AlignHCenter);
  operator_layout->addSpacerItem(new QSpacerItem(0, 8));

  // pwd edit
  operator_layout->addWidget(pwd_line_edit_, 0, Qt::AlignHCenter);
  operator_layout->addSpacerItem(new QSpacerItem(0, 10));

  operator_layout->addWidget(login_btn_, 0, Qt::AlignHCenter);
  operator_layout->addSpacerItem(new QSpacerItem(0, 40));

  operator_layout->addWidget(switch_user_btn_, 0, Qt::AlignHCenter);
  operator_layout->addSpacerItem(new QSpacerItem(0, 40));

  layout_->addLayout(operator_layout);

  icon_label_->installEventFilter(this);

  connect(switch_user_btn_, &QPushButton::pressed, this,
          [this]() { is_drag_ = true; });

  connect(min_btn_, &QPushButton::pressed, this, [this]() {
    is_drag_ = true;
    this->showMinimized();
  });

  connect(close_btn_, &QPushButton::pressed, this, [this]() {
    is_drag_ = true;
    this->close();
  });
}

void Launcher::loadStyleSheet(Theme theme) {
  qDebug() << "loadStyleSheet";
  if (!styleSheet().isEmpty() && theme == current_theme) {
    qDebug() << "styleSheet is empty";
    return;
  }

  current_theme = theme;

  QFile qss(QStringLiteral(":/day-custom.qss"));
  if (QFile::exists(":/day-custom.qss")) {
    qDebug() << "yes";
  }
  if (qss.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "none";
    setStyleSheet(QString::fromUtf8(qss.readAll()));
    qss.close();
  }
}

}  // namespace Window


