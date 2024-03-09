#include "control.hpp"

int main()
{
    // Instantiates every element of the stack.
    Model m;
    View v;
    Control c(m, v);

    // Starts the execution with the controller.
    c.run();

    return 0;
}