#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include <iomanip>

class View
{
public:
    void title();
    void instructions();
    void inputLayer();
    void inputError();
    void outputResult(std::string name, double value);
    char *getInput() { return input; }

private:
    char input[100];
};

#endif