#include "ui/widgets/mb_window.h"

#include "QWKWidgets/widgetwindowagent.h"
#include "ui/widgets/windowbar.h"
#include "ui/widgets/button.h"

#include "config.h"

#include <QApplication>
#include <QMenuBar>
#include <QTimer>
#include <QVBoxLayout>

namespace Ui {

static inline void emulateLeaveEvent(QWidget* widget) {
  Q_ASSERT(widget);
  if (!widget) {
    return;
  }
  QTimer::singleShot(0, widget, [widget]() {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    const QScreen* screen = widget->screen();
#else
        const QScreen *screen = widget.windowHandle()->screen();
#endif
    const QPoint globalPos = QCursor::pos(screen);
    if (!QRect(widget->mapToGlobal(QPoint(0, 0)), widget->size())
             .contains(globalPos)) {
      QCoreApplication::postEvent(widget, new QEvent(QEvent::Leave));
      if (widget->testAttribute(Qt::WA_Hover)) {
        const QPoint localPos = widget->mapFromGlobal(globalPos);
        const QPoint scenePos = widget->window()->mapFromGlobal(globalPos);
        static constexpr const auto oldPos = QPoint();
        const Qt::KeyboardModifiers modifiers =
            QGuiApplication::keyboardModifiers();
#if (QT_VERSION >= QT_VERSION_CHECK(6, 4, 0))
        const auto event = new QHoverEvent(QEvent::HoverLeave, scenePos,
                                           globalPos, oldPos, modifiers);
        Q_UNUSED(localPos);
#elif (QT_VERSION >= QT_VERSION_CHECK(6, 3, 0))
                const auto event = new QHoverEvent(QEvent::HoverLeave, localPos, globalPos, oldPos, modifiers);
                Q_UNUSED(scenePos);
#else
                const auto event = new QHoverEvent(QEvent::HoverLeave, localPos, oldPos, modifiers);
                Q_UNUSED(scenePos);
#endif
        QCoreApplication::postEvent(widget, event);
      }
    }
  });
}

MbWindow::MbWindow(QWidget* parent) : QWidget(parent) {
  // this->setStyleSheet("QWidget { background-color: white; }");


  // layout_ = new QVBoxLayout(this);
  setMinimumSize(Cfg::windowMinWidth, Cfg::windowMinHeight);
  installWindowAgent();
  layout_->setContentsMargins(QMargins());
  layout_->setSpacing(0);
  this->setLayout(layout_);
  agent_->centralize();

}

MbWindow::~MbWindow() = default;

void MbWindow::setTitle(const QString& title)
{
}

void MbWindow::setMinimumSize(int w, int h)
{ QWidget::setMinimumSize(QSize(w, h)); }


void MbWindow::setMinimumSize(QSize size)
{ QWidget::setMinimumSize(size); }

void MbWindow::installWindowAgent() {
  layout_ = new QVBoxLayout();
  agent_ = new QWK::WidgetWindowAgent(this);
  agent_->setup(this);

  auto menuBar = [this]() {
    Q_UNUSED(this)
    auto menuBar = new QMenuBar();

        // auto file = new QMenu(tr("File(&F)"), menuBar);
        // file->addAction(new QAction(tr("New(&N)"), menuBar));
        // file->addSeparator();

        // auto edit = new QMenu(tr("Edit(&E)"), menuBar);
        // edit->addAction(new QAction(tr("Undo(&U)"), menuBar));
        // edit->addAction(new QAction(tr("Redo(&R)"), menuBar));


        // menuBar->addMenu(file);
        // menuBar->addMenu(edit);

    return menuBar;
  }();
  menuBar->setObjectName(QStringLiteral("win-menu-bar"));

  auto titleLabel = new QLabel();
  titleLabel->setAlignment(Qt::AlignCenter);
  titleLabel->setObjectName(QStringLiteral("win-title-label"));

  auto iconBtn = new Button();
  // auto iconBtn = new QPushButton();
  iconBtn->setObjectName(QStringLiteral("icon-button"));
  // iconBtn->setMinimumSize(40, 30);
  iconBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto minBtn = new Button();
  // auto minBtn = new QPushButton();
  minBtn->setObjectName(QStringLiteral("min-button"));
  minBtn->setProperty("system-button", true);
  // minBtn->setMinimumSize(40, 30);
  minBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto maxBtn = new Button();
  // auto maxBtn = new QPushButton();
  maxBtn->setCheckable(true);
  maxBtn->setObjectName(QStringLiteral("max-button"));
  maxBtn->setProperty("system-button", true);
  // maxBtn->setIcon(QIcon("F:/MyProject/TtiGoneChat/TtiGoneChat/res/ui/icons/sys/_full_screen.svg"));
  // qDebug() << maxBtn->icon();
  // maxBtn->setStyleSheet("background-color:yellow");
  // maxBtn->setMinimumSize(40, 30);
  maxBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto closeBtn = new Button();
  // auto closeBtn = new QPushButton();
  closeBtn->setObjectName(QStringLiteral("close-button"));
  // closeBtn->setIcon(QIcon());
  // closeBtn->setMinimumSize(40, 30);
  closeBtn->setProperty("system-button", true);
  // qDebug() << closeBtn->icon();
  closeBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto windowbar = new WindowBar();
  qDebug() << windowbar->frameRect();

  windowbar->setIconButton(iconBtn);
  windowbar->setMinButton(minBtn);
  windowbar->setMaxButton(maxBtn);
  windowbar->setCloseButton(closeBtn);

  windowbar->setTitleLabel(titleLabel);
  windowbar->setMenuBar(menuBar);

  windowbar->setHostWidget(this);

  agent_->setTitleBar(windowbar);
  agent_->setSystemButton(QWK::WindowAgentBase::WindowIcon, iconBtn);
  agent_->setSystemButton(QWK::WindowAgentBase::Minimize, minBtn);
  agent_->setSystemButton(QWK::WindowAgentBase::Maximize, maxBtn);
  agent_->setSystemButton(QWK::WindowAgentBase::Close, closeBtn);

  agent_->setHitTestVisible(menuBar, true);

  layout_->setMenuBar(windowbar);

  // QWidget* w = new QWidget();
  // w->setMinimumHeight(200);
  // // w->setStyleSheet("background-color:yellow");

  // // w->setProperty("TitleBar", true);

  // QVBoxLayout* t = new QVBoxLayout(w);
  // t->setContentsMargins(QMargins());
  // t->setSpacing(0);
  // t->setMenuBar(windowbar);

  // // 有问题
  // //layout_->addLayout(t);
  // layout_->addWidget(w);
  QWidget *wt = new QWidget();
  wt->setStyleSheet("background-color: #F3F3F3");
  layout_->addWidget(wt);

  connect(iconBtn, &QAbstractButton::clicked, agent_, [this, iconBtn] {
      iconBtn->setProperty("double-click-close", false);

      // WindowBar's icon show a menu to choose
      QTimer::singleShot(75, agent_, [this, iconBtn]() {
          if (iconBtn->property("double-click-close").toBool()) {
              return;
          }
          agent_->showSystemMenu(iconBtn->mapToGlobal(QPoint(0, iconBtn->height())));
      });
  });

  // connect(iconBtn, &Button::doubleClicked, this, [iconBtn, this]() {
  //     iconBtn->setProperty("double-click-close", true);
  //     close();
  // });
  // connect(iconBtn, &QPushButton::doubleClicked, this, [iconBtn, this]() {
  //     iconBtn->setProperty("double-click-close", true);
  //     close();
  // });

  connect(windowbar, &WindowBar::minimizeRequested, this,
          &QWidget::showMinimized);
  connect(windowbar, &WindowBar::maximizeRequested, this,
          [this, maxBtn](bool max) {
            if (max) {
              showMaximized();
            } else {
              showNormal();
            }
            // slove hover event
            emulateLeaveEvent(maxBtn);
          });
  connect(windowbar, &WindowBar::closeRequested, this,
          &QWidget::close);
}

}  // namespace Ui
