#include "main.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>

#include <string>

QVector<QVariant> loadJsonValues(QString fileName)
{
    QVector<QVariant> ret;

    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());

    QJsonObject obj = doc.object();
    QVariantMap rootObj = obj.toVariantMap();
    QVariantList valueList = rootObj["values"].toList();

    qDebug() << "Total values: " << valueList.size();

    return valueList.toVector();
}

double calculateMedianValue(QVector<QVariant> values)
{
    if(values.empty()) return 0.0;
    if(values.size() == 1) return values[0].toDouble();
    if(values.size() % 2 == 0) {
        return (values[values.size() / 2].toDouble() + values[values.size() / 2 - 1].toDouble()) / 2;
    } else {
        return values[values.size() / 2].toDouble();
    }
}

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
