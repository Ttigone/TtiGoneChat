#ifndef APP_H
#define APP_H

#include <QWidget>

namespace Window {

class Launcher;

} // namespace Window

class App : public QWidget
{
    Q_OBJECT

public:
    App(QWidget *parent = nullptr);
    ~App();

private:
    // std::unique_ptr<Window::Launcher> launcher_;
};

#endif // APP_H
