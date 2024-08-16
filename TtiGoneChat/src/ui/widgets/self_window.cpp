#include "ui/widgets/self_window.h"

#include "QWKWidgets/widgetwindowagent.h"
#include "ui/widgets/windowbar.h"
#include "ui/widgets/windowbar_button.h"
#include "layout/vertical_layout.h"

#include "config.h"

#include <QApplication>
#include <QMenuBar>
#include <QTimer>
#include <QVBoxLayout>

//#include 

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

SelfWindow::SelfWindow(QWidget* parent)
    : QWidget(parent),
      layout_(new QVBoxLayout(this)),
      central_widget(new QWidget),
      //central_widget_layout_(new Layout::VerticalLayout(central_widget)) {
      central_widget_layout_(new QVBoxLayout(central_widget)) {

  //central_widget->setLayout(central_widget_layout_);
  //central_widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  central_widget_layout_->setContentsMargins(QMargins());
  central_widget_layout_->setSpacing(0);

  setMinimumSize(Cfg::windowMinWidth, Cfg::windowMinHeight);
  installWindowAgent();
  layout_->setContentsMargins(QMargins());
  layout_->setSpacing(0);
  this->setLayout(layout_);
  agent_->centralize();
  //qDebug() << agent_->titleBar()->geometry();
  //qDebug() << this->geometry();
}

SelfWindow::~SelfWindow() = default;

void SelfWindow::setContentWidget(QWidget* w) {
	central_widget_layout_->addWidget(w);
	//central_widget_layout_->addWidget(w, 0, Qt::AlignCenter);
}

void SelfWindow::setTitle(const QString& title) {}

void SelfWindow::setMinimumSize(int w, int h) {
  QWidget::setMinimumSize(QSize(w, h));
}

void SelfWindow::setMinimumSize(QSize size) { QWidget::setMinimumSize(size); }

void SelfWindow::installWindowAgent() {
  //layout_ = new QVBoxLayout();
  //layout_ = new Layout::VerticalLayout(this);
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

  auto iconBtn = new WindowbarButton();
  // auto iconBtn = new QPushButton();
  iconBtn->setObjectName(QStringLiteral("icon-button"));
  iconBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto minBtn = new WindowbarButton();
  // auto minBtn = new QPushButton();
  minBtn->setObjectName(QStringLiteral("min-button"));
  minBtn->setProperty("system-button", true);
  minBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto maxBtn = new WindowbarButton();
  // auto maxBtn = new QPushButton();
  maxBtn->setCheckable(true);
  maxBtn->setObjectName(QStringLiteral("max-button"));
  maxBtn->setProperty("system-button", true);
  maxBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto closeBtn = new WindowbarButton();
  // auto closeBtn = new QPushButton();
  closeBtn->setObjectName(QStringLiteral("close-button"));
  closeBtn->setProperty("system-button", true);
  closeBtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  auto windowbar = new WindowBar();

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



  //QWidget *wt = new QWidget(central_widget);
  //QWidget *wt = new QWidget();
  //////// 一定要设置高度, 因为 layout 会自动调整 widget 的高度 默认 0
  //wt->setMinimumHeight(30);
  //wt->setStyleSheet(
  //    "background-color: Coral; border: 1px solid #000000;");

  //setContentWidget(wt);


	//ConnerButton *n = new ConnerButton();
 // layout_->addWidget(n);

  layout_->addWidget(central_widget);


  connect(iconBtn, &QAbstractButton::clicked, agent_, [this, iconBtn] {
    iconBtn->setProperty("double-click-close", false);

    // WindowBar's icon show a menu to choose
    QTimer::singleShot(75, agent_, [this, iconBtn]() {
      if (iconBtn->property("double-click-close").toBool()) {
        return;
      }
      agent_->showSystemMenu(
          iconBtn->mapToGlobal(QPoint(0, iconBtn->height())));
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
  connect(windowbar, &WindowBar::closeRequested, this, &QWidget::close);
}

bool SelfWindow::checkLayout(const QString &widget_name) {
  for (int i = 0; i < layout_->count(); ++i) {
    QLayoutItem* item = layout_->itemAt(i);
    auto w = item->widget();
    if (w && w->objectName() == widget_name) {
      return true;
    }
  }
  return false;
}
}  // namespace Ui
