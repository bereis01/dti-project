#include "model.hpp"

PetShop::PetShop(std::string _name, double _distance, double _weekSmallPrice,
                 double _weekBigPrice, double _weekendSmallPrice, double _weekendBigPrice)
{
    name = _name;
    distance = _distance;
    weekSmallPrice = _weekSmallPrice;
    weekBigPrice = _weekBigPrice;
    weekendSmallPrice = _weekendSmallPrice;
    weekendBigPrice = _weekendBigPrice;
}

// Database result capturing function.
// Puts all queried rows in a stream object.
int queryResult(void *data, int numOfRows, char **values, char **rows)
{
    for (int i = 0; i < numOfRows; i++)
    {
        *((std::stringstream *)data) << values[i] << " ";
    }
    *((std::stringstream *)data) << std::endl;

    return 0;
}

// Computes which shop is cheaper based on a vector of shops.
std::pair<std::string, double> Model::computeCheaper(int day, int month, int year, double numSmall, double numBig)
{
    retrieveData();

    // Computes cheapest and returns result.
    PetShop cheapest = *shops.begin();
    std::string name = cheapest.getName();
    double minDist = cheapest.getDistance();
    double minPrice = std::numeric_limits<double>::infinity();
    for (auto it = shops.begin(); it < shops.end(); it++)
    {
        double dist, price;

        dist = it->getDistance();
        // Computes price.
        int date = dayOfWeek(day, month, year);
        if (date == 0 || date == 6)
        {
            price = numSmall * it->getWeekendSmallPrice() + numBig * it->getWeekendBigPrice();
        }
        else
        {
            price = numSmall * it->getWeekSmallPrice() + numBig * it->getWeekBigPrice();
        }

        // Compares and, if equal, checks distance.
        if ((price < minPrice) || (price == minPrice && dist < minDist))
        {
            cheapest = *it;
            name = cheapest.getName();
            minDist = cheapest.getDistance();
            minPrice = price;
        }
    }

    std::replace(name.begin(), name.end(), '_', ' ');
    return std::pair<std::string, double>(name, minPrice);
}

// Retrieves data from database.
void Model::retrieveData()
{
    // Opening database.
    sqlite3 *db;
    if(sqlite3_open("db/petshops.db", &db)) { std::cout << "ERROR OPENING DATABASE!" << std::endl; exit(-1); };

    // Querying info.
    std::stringstream *result = new std::stringstream;
    std::string query = "SELECT * FROM PETSHOP;";
    if(sqlite3_exec(db, query.c_str(), queryResult, (void *)result, NULL)) { std::cout << "ERROR IN DATABASE QUERY!" << std::endl; exit(-1); };

    // Storing info locally.
    char aux[1000];
    result->getline(aux, sizeof(aux));
    while (!result->eof())
    {
        int id;
        std::string name;
        double distance, weekSmallPrice, weekBigPrice, weekendSmallPrice, weekendBigPrice;
        std::stringstream temp(aux);
        temp >> id >> name >> distance >> weekSmallPrice >> weekBigPrice >> weekendSmallPrice >> weekendBigPrice;
        shops.push_back(PetShop(name, distance, weekSmallPrice, weekBigPrice, weekendSmallPrice, weekendBigPrice));

        result->getline(aux, 1000);
    }

    // Cleaning and closing database.
    delete result;
    if(sqlite3_close(db)) { std::cout << "ERROR IN DATABASE QUERY!" << std::endl; exit(-1); };
}

// Made by rathbhupendra.
// Extracted from GeeksForGeeks.
// Adapted for naming conventions.
int dayOfWeek(int d, int m, int y)
{
    static int t[] = {0, 3, 2, 5, 0, 3,
                      5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 +
            y / 400 + t[m - 1] + d) %
           7;
}