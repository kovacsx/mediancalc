#include "main.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>

#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    auto fileName = QFileDialog::getOpenFileName(this,
        tr("Open JSON file"), "./", tr("JSON files (*.json)"));

    qDebug() << "Load file: " << fileName;

    if(fileName.isEmpty()) {
        qDebug() << "Empty file!";
        return;
    }


    QFile file;
    file.setFileName(fileName);

    auto values = loadValuesFromJson(fileName.toStdString());

    if(values.empty()) {
        qDebug() << "No values loaded!";
        return;
    }

    for(const auto &value : values)
    {
        new QListWidgetItem(QString::number(value), ui->valuesWidget);
    }

    auto medianValue = calculateMedian(values);

    qDebug() << "median: " << medianValue;

    ui->medianWidget->setText(QString::number(medianValue));
}
