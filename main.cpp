#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

#define CHANGE_LANGUAGE 2

int main(int argc, char *argv[])
{
  int ret_code;

  do {
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Sochka Olexandr");
    QCoreApplication::setApplicationName("Minesweeper");
    QCoreApplication::setApplicationVersion("2.0dev");
    QTranslator* translator = new QTranslator;
    QString lng = Settings()
        .value("language", QLocale::system().name())
        .toString().left(2);
    //lng="en";
    QString translate_file_path = QDir::currentPath() + "/minesweeper_" + lng + ".qm";
    translator->load(translate_file_path);
    app.installTranslator(translator);
    MainWindow w;
    w.show();
    ret_code = app.exec();
  } while(ret_code == CHANGE_LANGUAGE);

  return ret_code;
}