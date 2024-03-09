#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <algorithm>
#include <sqlite3.h>

class PetShop
{
public:
    PetShop(std::string _name, double _distance, double _weekSmallPrice,
            double _weekBigPrice, double _weekendSmallPrice, double _weekendBigPrice);
    std::string getName() { return name; }
    double getDistance() { return distance; }
    double getWeekSmallPrice() { return weekSmallPrice; }
    double getWeekBigPrice() { return weekBigPrice; }
    double getWeekendSmallPrice() { return weekendSmallPrice; }
    double getWeekendBigPrice() { return weekendBigPrice; }

private:
    std::string name;
    double distance;
    double weekSmallPrice;
    double weekBigPrice;
    double weekendSmallPrice;
    double weekendBigPrice;
};

class Model
{
public:
    std::pair<std::string, double> computeCheaper(int day, int month, int year, double numSmall, double numBig);

private:
    void retrieveData();

    std::vector<PetShop> shops;
};

// Auxiliary functions.
int queryResult(void *data, int numOfRows, char **values, char **rows);
int dayOfWeek(int d, int m, int y);

#endif