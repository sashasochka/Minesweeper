#include <QtGui>
#include "mainwindow.h"

#define CHANGE_LANGUAGE 2

int main(int argc, char *argv[])
{

    int ret_code;
    do
    {
        QApplication app(argc, argv);

        QCoreApplication::setOrganizationName("Sochka Olexandr");
        QCoreApplication::setApplicationName("Minesweeper");
        QCoreApplication::setApplicationVersion("1.0beta");

        QTranslator* translator=new QTranslator;

        QString lng=QSettings()
                .value("language",QLocale::system().name())
                .toString();
        //lng="en";

        QString translate_file_path=
#ifdef QT_DEBUG
                     "D:\\qt_c++\\minesweeper"
#else
                     QDir::currentPath()+
#endif
                     "\\minesweeper_" +lng;

        //qDebug()<<translate_file_path;

        //qDebug()<<
        translator->load(translate_file_path);

        app.installTranslator(translator);


        MainWindow w;
        w.show();

        ret_code=app.exec();

    } while(ret_code==CHANGE_LANGUAGE);

    return ret_code;
}
