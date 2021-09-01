#include <QtWidgets/QApplication>
#include <QWidget>
#include <QTextCodec>
#include <QTime>
#include <locale>
#include "Live2DWidget.h"
#include "Settings.h"

int main(int argc, char *argv[])
{
    Settings::Load();

    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    
    Live2DWidget* w = new Live2DWidget("Lilywhite");

    a.connect(w, &Live2DWidget::CloseSignal, &a, &QApplication::exit);

    return a.exec();
}