#include "mainwindow.h"
#include "settings.h"

#include <QApplication>
#include <QTranslator>

const QString organizationName = "Sochka Oleksandr";
const QString appName = "Minesweeper";
const QString appVersion = "2.0";

int main(int argc, char *argv[]) {
    int returnCode = 0;
    do {
        QApplication app(argc, argv);
        QCoreApplication::setOrganizationName(organizationName);
        QCoreApplication::setApplicationName(appName);
        QCoreApplication::setApplicationVersion(appVersion);
        const QString language = Settings().value("language", QLocale::system().name())
                .toString().left(2);
        const QString translation_path = QDir::currentPath() + "/minesweeper_" + language + ".qm";
        QTranslator* translator = new QTranslator();
        translator->load(translation_path);
        app.installTranslator(translator);
        MainWindow w;
        w.show();
        returnCode = app.exec();
    } while (returnCode == changeLanguageReturnCode);

    return returnCode;
}
