#include "TransparentWindow.h"
#include <QCoreApplication>
#include <QScreen>
#include <QtWidgets/QApplication>

#ifdef Q_OS_LINUX
#include <X11/extensions/shape.h>
#include <QX11Info>
#endif

void TransparentWindow::Setup(QWidget* w, bool expandToStateBar)
{
    w->setWindowFlag(Qt::WindowType::MSWindowsOwnDC, false);
    w->setWindowFlag(Qt::FramelessWindowHint);
    w->setWindowFlag(Qt::Tool);
    w->setWindowFlag(Qt::WindowStaysOnTopHint);
    w->setAttribute(Qt::WA_TranslucentBackground);
    QSize screenSize;
    if (!expandToStateBar)
        screenSize = QApplication::primaryScreen()->availableGeometry().size();
    else
        screenSize = QApplication::primaryScreen()->size();
    w->setGeometry(0, 0, screenSize.width(), screenSize.height());
    TransparentWindow::SetTransparentForMouse(w, true);
}

void TransparentWindow::SetTransparentForMouse(QWidget* w, bool flag)
{
#ifdef Q_OS_LINUX
    if (flag) {
        XShapeCombineRectangles(QX11Info::display(), w->winId(), ShapeInput, 0, 0, nullptr, 0, ShapeSet, YXBanded);
    } else {
        auto window = w->window();
        XRectangle rect = {
            0, 0, static_cast<unsigned short>(window->width()), static_cast<unsigned short>(window->height())
        } ;
        XShapeCombineRectangles(QX11Info::display(), w->winId(), ShapeInput, 0, 0, &rect, 1, ShapeSet, YXBanded);
    }
#endif
}

bool TransparentWindow::processNativeEvent(QWidget* w, const QByteArray& b, void* m, long* r)
{
    return false;
}
