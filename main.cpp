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
    QString lng = QSettings()
                  .value("language", QLocale::system().name())
                  .toString();
    //lng="en";
    QString translate_file_path =
#ifdef QT_DEBUG
      "~/minesweeper2/";
#else
      QDir::currentPath();
#endif
    translator->load(translate_file_path);
    app.installTranslator(translator);
    MainWindow w;
    w.show();
    ret_code = app.exec();
  } while(ret_code == CHANGE_LANGUAGE);

  return ret_code;
}