#include "field.h"

#include "windialog.h"
#include "defeat.h"
#include "optionsdialog.h"
#include "statisticswidget.h"
#include "ui_statistics.h"
#include "cell.h"

#include <QtCore>

Field::Field(QWidget *parent) :
    QWidget{parent}
    , f_layout{new QGridLayout}
    , settings{new Settings}
    , cells_are_filled{false}
    , won{false}
    , date{QDate::currentDate()}
{
    setAttribute(Qt::WA_DeleteOnClose);
    getSettings();
    const int a = 32;
    parentWidget()->resize(a * cols, a * rows + 60);
    parentWidget()->setMinimumSize(a * cols / 1.4, a * rows / 1.4);
    f_layout->setMargin(0);
    f_layout->setSpacing(0);
    cells.assign(rows + 2, std::vector<Cell*>(cols + 2));

    for(size_t row = 0; row < cells.size(); row++) {
        for(size_t col = 0; col < cells[row].size(); col++) {
            if(!row || !col || row == cells.size() - 1 || col == cells[row].size() - 1) {
                cells[row][col] = new Cell(row, col, false, this);
            } else {
                cells[row][col] = new Cell(row, col, true, this);
                connect(cells[row][col], SIGNAL(zeroBombNeighbours(QPoint)),
                        SLOT(openNeighbours(QPoint))
                       );
                connect(cells[row][col], SIGNAL(cellOpened()),
                        SLOT(testIfWin())
                       );
                connect(cells[row][col], SIGNAL(defeat()),
                        SLOT(defeatGame())
                       );
                connect(cells[row][col], SIGNAL(beforeOpened(int, int)),
                        SLOT(fillCells(int, int))
                       );
                f_layout->addWidget(cells[row][col], row - 1, col - 1);
            }

            QApplication::processEvents();
        }
    }

    qsrand(QTime::currentTime().msec());
    setLayout(f_layout.get());
}


void Field::fillCells(int exclude_x, int exclude_y) {
    if(cells_are_filled) {
        return;
    }

    time.start();
    int minesLeft = mines;

    while (minesLeft) {
        int rand_x = qrand() % cols + 1;
        int rand_y = qrand() % rows + 1;

        if(rand_x == exclude_x && rand_y == exclude_y) {
            continue;
        }

        Cell* rand_cell = cells[rand_y][rand_x];

        if(!(rand_cell->empty())) {
            continue;
        }

        --minesLeft;
        rand_cell->setBomb();
    }

    cells_are_filled = true;
}

int Field::count_neighbour_bombs(QPoint pt) {
    int neighbours = 0;

    for (int dy = -1; dy <= 1; ++dy)
        for (int dx = -1; dx <= 1; ++dx)
            if (cells[pt.ry() + dy][pt.rx() + dx] != nullptr  &&
                    !(cells[pt.ry() + dy][pt.rx() + dx]->empty())) {
                neighbours++;
            }

    return neighbours;
}

QSize Field::cellSize() {
    return cells[1][1]->size();
}

void Field::openNeighbours(QPoint pos) {
    for(int y = 0; y < 3; y++)
        for (int x = 0; x < 3; ++x) {
            cells[y + pos.ry() - 1][x + pos.rx() - 1]->open();
        }
}

void Field::testIfWin() {
    if(won) {
        return;
    }

    won = true;

    for(int row = 1; row <= rows; row++)
        for(int col = 1; col <= cols; col++)
            if (cells[row][col]->empty() && !cells[row][col]->opened) {
                won = false;
            }

    if(won) {
        emit win();
    }
}

void Field::win() {
    WinDialog* windialog = new WinDialog;
    connect(windialog->findChild<QPushButton*>("playAgainBtn"), SIGNAL(clicked()),
            windialog,  SLOT(close()));
    connect(windialog, SIGNAL(finished(int)),
            SIGNAL(needRestart()));
    int* bestTime = nullptr;

    if (rows == 9  && cols == 9  && mines == 10) {
        bestTime = &bestBeginnerTime;
    } else if(rows == 16 && cols == 16 && mines == 40) {
        bestTime = &bestIntermediateTime;
    } else if(rows == 16 && cols == 30 && mines == 99) {
        bestTime = &bestAdvancedTime;
    }

    gamesPlayed++;
    gamesWon++;

    if(bestTime != nullptr) {
        if (*bestTime > time.elapsed() || !*bestTime) {
            *bestTime = time.elapsed();
            windialog->enableBestTimeCongratulations();
        }

        windialog->setBestTime(*bestTime);
    } else {
        windialog->findChild<QLabel*>("bestTime")->deleteLater();
    }

    windialog->setTime(time);
    windialog->setDate(date);
    windialog->setPlayedGames(gamesPlayed);
    windialog->setWonGames(gamesWon);
    windialog->setPercentage(static_cast<float>(gamesWon) / gamesPlayed * 100);
    windialog->show();
}

void Field::defeatGame() {
    Defeat* defeat = new Defeat;
    connect(defeat->findChild<QPushButton*>("play_againBtn"), SIGNAL(clicked()),
            SIGNAL(needRestart()));
#ifdef QT_NO_DEBUG
    connect(defeat, SIGNAL(finished(int)),
            SIGNAL(needRestart()));
#endif
    connect(defeat->findChild<QPushButton*>("play_againBtn"), SIGNAL(clicked()),
            defeat, SLOT(close()));
    int bestTime = 0;

    if (rows == 9  && cols == 9  && mines == 10) {
        bestTime = bestBeginnerTime;
    } else if(rows == 16 && cols == 16 && mines == 40) {
        bestTime = bestIntermediateTime;
    } else if(rows == 16 && cols == 30 && mines == 99) {
        bestTime = bestAdvancedTime;
    }

    gamesPlayed++;

    if(bestTime) {
        defeat->setBestTime(bestTime);
    } else {
        defeat->findChild<QLabel*>("bestTime")->deleteLater();
    }

    defeat->setTime(time);
    defeat->setDate(date);
    defeat->setPlayedGames(gamesPlayed);
    defeat->setWonGames(gamesWon);
    defeat->setPercentage(static_cast<float>(gamesWon) / gamesPlayed * 100);
    defeat->show();
}

void Field::optionsDialog() {
    auto dialog = new OptionsDialog;
    connect(dialog, SIGNAL(settings_changed(int, int, int)), SLOT(changeSettings(int, int, int)));
    connect(dialog, SIGNAL(askMark_status_changed(bool)), SLOT(askMarkAllow(bool)));
    connect(dialog, SIGNAL(language_changed(QString)), SLOT(changeLanguage(QString)));
    dialog->show();
    dialog->setAttribute(Qt::WA_DeleteOnClose);
}

void Field::getSettings() {
    rows = settings->value("rows", 9).toInt();
    cols = settings->value("cols", 9).toInt();
    mines = settings->value("mines", 10).toInt();
    askMark = settings->value("askMark", true).toBool();
    bestBeginnerTime = settings->value("bestTime/beginner", 0).toInt();
    bestIntermediateTime = settings->value("bestTime/intermediate", 0).toInt();
    bestAdvancedTime = settings->value("bestTime/advanced", 0).toInt();
    gamesPlayed = settings->value("gamesPlayed", 0).toInt();
    gamesWon = settings->value("gamesWon", 0).toInt();
    lng = settings->value("language", QLocale::system().name()).toString();
}

void Field::saveSettings() {
    settings->setValue("rows", rows);
    settings->setValue("cols", cols);
    settings->setValue("mines", mines);
    settings->setValue("askMark", askMark);
    settings->setValue("/bestTime/beginner", bestBeginnerTime);
    settings->setValue("/bestTime/intermediate", bestIntermediateTime);
    settings->setValue("/bestTime/advanced", bestAdvancedTime);
    settings->setValue("gamesPlayed", gamesPlayed);
    settings->setValue("gamesWon", gamesWon);
    settings->setValue("language", lng);
}

void Field::changeSettings(int rows, int cols , int mines) {
    this->rows = rows;
    this->cols = cols;
    this->mines = mines;
    saveSettings();
    emit needRestart();
}

void Field::askMarkAllow(bool allow) {
    settings->setValue("askMark", this->askMark = allow);
    askMark = allow;
}

void Field::statistics_dialog() {
    auto stat_dialog = new StatisticsWidget;
    auto ui = new Ui::Statistics;
    ui->setupUi(stat_dialog);
    int bestTime = 0;

    if (rows == 9  && cols == 9  && mines == 10) {
        bestTime = bestBeginnerTime;
    } else if(rows == 16 && cols == 16 && mines == 40) {
        bestTime = bestIntermediateTime;
    } else if(rows == 16 && cols == 30 && mines == 99) {
        bestTime = bestAdvancedTime;
    }

    stat_dialog->setBestTime(bestTime);
    stat_dialog->setPlayedGames(gamesPlayed);
    stat_dialog->setWonGames(gamesWon);
    stat_dialog->setPercentage(static_cast<float>(gamesWon) / gamesPlayed * 100);
    connect(stat_dialog->findChild<QPushButton*>("clearBtn"), SIGNAL(released()),
            SLOT(clearStatistics()));
    stat_dialog->show();
}

void Field::clearStatistics() {
    settings->remove("gamesPlayed");
    settings->remove("gamesWon");
    settings->remove("bestTime");
    bestBeginnerTime = bestIntermediateTime =
                           bestAdvancedTime = gamesPlayed = gamesWon = 0;
}

void Field::changeLanguage(QString new_lng) {
    lng = new_lng;
    saveSettings();
    qApp->exit(changeLanguageReturnCode);
}

Field::~Field() {
    saveSettings();
}
