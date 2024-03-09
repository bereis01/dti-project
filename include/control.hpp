#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <regex>
#include "model.hpp"
#include "view.hpp"

class Control
{
public:
    Control(Model _m, View _v);
    void run();

private:
    Model m;
    View v;
};

#endif