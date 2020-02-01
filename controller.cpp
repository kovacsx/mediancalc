#include "controller.h"

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


