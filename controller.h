#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QDebug>
#include <QVector>
#include <QVariant>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

QVector<QVariant> loadJsonValues(QString fileName);
double calculateMedianValue(QVector<QVariant> values);

#endif // CONTROLLER_H
