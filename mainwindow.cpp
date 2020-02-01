#include "controller.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QVector>

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

    ui->valuesWidget->clear();

    auto fileName = QFileDialog::getOpenFileName(this,
        tr("Open JSON file"), "../../../../", tr("JSON files (*.json)"));

    qDebug() << "Load file: " << fileName;

    if(fileName.isEmpty()) {
        qDebug() << "Empty file!";
        return;
    }

    auto values = loadJsonValues(fileName);
    if(values.empty()) {
        qDebug() << "No values loaded!";
        return;
    }

    for(const auto &value : values)
    {
        new QListWidgetItem(value.toString(), ui->valuesWidget);
    }

    auto medianValue = calculateMedianValue(values);
    qDebug() << "median: " << medianValue;
    ui->medianWidget->setText(QString::number(medianValue));
}
