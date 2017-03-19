#include "notepad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon((QIcon)":/icons/mainIcon.png");
    MainWindow w;
    //setWindowFlags(Qt::Dialog)
    w.show();

    return a.exec();
}
