#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <vector>
#include <list>
#include "C:\Users\Ian\Documents\GitHub\wiPiTools\wiPiTools.h"
#include "inputwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_addOutputButton_clicked();

    void on_deleteButton_clicked();

    void on_outputsList_doubleClicked(const QModelIndex &index);

    void on_inputsList_doubleClicked(const QModelIndex &index);

    void on_addInputButton_clicked();

    void on_editOutputButton_clicked();

    void on_editInputButton_clicked();

private:
    std::vector<Output> outputs;
    std::vector<Input> inputs;
    std::vector<Delay> delays;
    Ui::MainWindow *ui;
    QStringListModel *modelOutputs;
    QStringListModel *modelInputs;
    void updateListBoxes();
    bool duplicateEntry(int pin);
};

#endif // MAINWINDOW_H
