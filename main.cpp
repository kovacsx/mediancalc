#include "main.h"
#include "mainwindow.h"

#include <QApplication>
#include <list>
#include <string>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

std::list<int> loadValuesFromJson(const std::string &fileName)
{
    std::list<int> ret = {1, 2, 4, 5, 6};

    return ret;
}


double calculateMedian(std::list<int> values)
{
    double ret = 0.0;

    if(values.empty()) {
        return ret;
    }

    values.sort();


    auto midElem = values.size() / 2;

    auto iter = values.begin();

    for(unsigned i = 0; i < midElem; ++i) {
        iter++;
    }

    if(values.size() % 2 == 1) {
        // odd number of elements, pick middle one
        return *iter;
    } else {
        // even number of elements, pick average of middle two elements
        ret += *iter;
        ++iter;
        return (ret + *iter) / 2.0;

    }

    return ret;
}
