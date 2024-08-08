#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H


class MainWindow;

namespace Local {
class Session;
} // namespace Local

namespace Window {

class SessionController;

}

class MainWidget final : public QWidget
{
public:
	MainWidget(QWidget* parent, not_null<Window::SessionController *> controller);
	~MainWidget();

	[[nodiscard]] Local::Session &session() const;
	[[nodiscard]] Window::SessionController &controller() const;

	/// @brief 是否是主要窗口
	[[nodiscard]] bool isPrimary() const;
	[[nodiscard]] bool isMainSectionShown() const;
	[[nodiscard]] bool isThirdSectionShown() const;

	void showAnimated(QPixmap old_content_cache, bool back = false);
	
	/// @brief 激活窗口
	void activate();

	/// @brief 展示窗口
	void windowShown();

private:
	void paintEvent(QPaintEvent* event) override;
	void resizeEvent(QResizeEvent* event) override;
	bool eventFilter(QObject* obj, QEvent* event) override;

private:
	void showFinished();
	void hideAll();
	void showAll();
	//void 

	//const Window::SessionController* controller_;
	//Window::SessionController* controller_;
	const not_null<Window::SessionController *> controller_;
	//const not_null<


};

#endif // MAIN_WIDGET_H
