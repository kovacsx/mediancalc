#ifndef MAIN_H
#define MAIN_H

#include <QString>
#include <QArray>

QArray<double> loadArrayFromJson(const Qstring &fileName);
double calculateMedian(std::list<int> values);

#endif // MAIN_H
