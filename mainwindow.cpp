#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modelOutputs = new QStringListModel();
    modelInputs = new QStringListModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::duplicateEntry(int pin)
{
    for(Input i : inputs)
    {
        if(i.get_pin() == pin)
        {
            std::cout << "Duplicate.. not adding.." << std::endl;
            return 1;
        }
    }
    for(Output o : outputs)
    {
        if(o.get_pin() == pin)
        {
            std::cout << "Duplicate.. not adding.." << std::endl;
            return 1;
        }
    }
    return 0;
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::updateListBoxes() {

    QStringList outputList, inputList;
    for(int i = 0; i < outputs.size(); i++)
    {
        QString tmp = QString::fromStdString(outputs.at(i).to_string());
        outputList << tmp;
    }
    modelOutputs->setStringList(outputList);
    ui->outputsList->setModel(modelOutputs);

    for(int i = 0; i < inputs.size(); i++)
    {
        QString tmp = QString::fromStdString(inputs.at(i).to_string());
        inputList << tmp;
    }
    modelInputs->setStringList(inputList);
    ui->inputsList->setModel(modelInputs);
}

void MainWindow::on_addOutputButton_clicked()
{
    std::string s = ui->outputPinText->text().toStdString();
    int pin = std::stoi(s);
    if(duplicateEntry(pin)) return;

    Output output(pin, ui->outputNameText->text().toStdString());
    outputs.push_back(output);
    updateListBoxes();
    std::cout << "Test " << output.to_string() <<  std::endl;
}

void MainWindow::on_deleteButton_clicked()
{
    int a = ui->outputsList->currentIndex().row();
    std::cout << a << std::endl;
}

void MainWindow::on_outputsList_doubleClicked(const QModelIndex &index)
{
    outputs.erase(outputs.begin() + index.row());
    updateListBoxes();
}

void MainWindow::on_inputsList_doubleClicked(const QModelIndex &index)
{
    inputs.erase(inputs.begin() + index.row());
    updateListBoxes();
}

void MainWindow::on_addInputButton_clicked()
{
    std::string s = ui->inputPinText->text().toStdString();
    int pin = std::stoi(s);
    if(duplicateEntry(pin)) return;
    Input input(pin, ui->inputNameText->text().toStdString());
    inputs.push_back(input);
    updateListBoxes();
    std::cout << "Test " << input.to_string() <<  std::endl;
}

void MainWindow::on_editOutputButton_clicked()
{
    int a = ui->outputsList->currentIndex().row();
    std::stringstream ss;
    ss << "Output #: " << a;

    QMessageBox messageBox;
    messageBox.setText(QString::fromStdString(ss.str()));
    messageBox.exec();
}

void MainWindow::on_editInputButton_clicked()
{
    int a = ui->inputsList->currentIndex().row();
    std::stringstream ss;
    ss << "Output #: " << a;

    QMessageBox messageBox;
    messageBox.setText(QString::fromStdString(ss.str()));
    messageBox.exec();
}
