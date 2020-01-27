#ifndef MAIN_H
#define MAIN_H

#include <list>
#include <string>

std::list<int> loadValuesFromJson(const std::string &fileName);
double calculateMedian(std::list<int> values);

#endif // MAIN_H
