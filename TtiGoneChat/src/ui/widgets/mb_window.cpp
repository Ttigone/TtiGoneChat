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
  this->setStyleSheet("QWidget { background-color: white; }");


  layout_ = new QVBoxLayout(this);
  layout_->setContentsMargins(QMargins());
  layout_->setSpacing(0);
  setMinimumSize(Cfg::windowMinWidth, Cfg::windowMinHeight);
  installWindowAgent();
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
  agent_ = new QWK::WidgetWindowAgent(this);
  agent_->setup(this);

  auto menuBar = [this]() {
    Q_UNUSED(this)
    auto menuBar = new QMenuBar();

    auto file = new QMenu(tr("File(&F)"), menuBar);
    file->addAction(new QAction(tr("New(&N)"), menuBar));
    file->addSeparator();

    menuBar->addMenu(file);

    return menuBar;
  }();
  auto titleLabel = new QLabel();
  titleLabel->setAlignment(Qt::AlignCenter);
  titleLabel->setObjectName(QStringLiteral("win-title-label"));

  auto iconButton = new Button();
  iconButton->setObjectName(QStringLiteral("icon-button"));
  iconButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto minBtn = new Button();
  minBtn->setObjectName(QStringLiteral("min-button"));
  minBtn->setProperty("system-button", true);
  minBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto maxBtn = new Button();
  maxBtn->setCheckable(true);
  maxBtn->setObjectName(QStringLiteral("max-button"));
  maxBtn->setProperty("system-button", true);
  maxBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto closeBtn = new Button();
  closeBtn->setObjectName(QStringLiteral("close-button"));
  closeBtn->setIcon(QIcon(":/icon/login_close.svg"));
  closeBtn->setMinimumSize(40, 30);
  closeBtn->setProperty("system-button", true);
  closeBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto windowbar = new WindowBar();

  windowbar->setIconButton(iconButton);
  windowbar->setMinButton(minBtn);
  windowbar->setMaxButton(maxBtn);
  windowbar->setCloseButton(closeBtn);

  windowbar->setMenuBar(menuBar);
  windowbar->setTitleLabel(titleLabel);
  windowbar->setHostWidget(this);

  agent_->setTitleBar(windowbar);
  agent_->setSystemButton(QWK::WindowAgentBase::WindowIcon, iconButton);
  agent_->setSystemButton(QWK::WindowAgentBase::Minimize, minBtn);
  agent_->setSystemButton(QWK::WindowAgentBase::Maximize, maxBtn);
  agent_->setSystemButton(QWK::WindowAgentBase::Close, closeBtn);
  agent_->setHitTestVisible(menuBar, true);

  QWidget* w = new QWidget();
  QVBoxLayout* t = new QVBoxLayout(w);
  t->setContentsMargins(QMargins());
  t->setSpacing(0);
  t->setMenuBar(windowbar);

  // ÓÐÎÊÌâ
  //layout_->addLayout(t);
  layout_->addWidget(w);
  layout_->addWidget(new QWidget());

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