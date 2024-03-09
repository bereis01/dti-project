#include "control.hpp"

Control::Control(Model _m, View _v)
{
    m = _m;
    v = _v;
}

// Main execution cycle.
void Control::run()
{
    v.title();
    v.instructions();

    while (1)
    {
        v.inputLayer();

        // Once the input layer is called, it is assumed that the view stores the input.
        // Processing the input.
        char *input = v.getInput();

        // Stops if there is no input (user pressed enter).
        if (!strcmp(input, ""))
        {
            break;
        }

        // Checks if the input matches the specified layout.
        if (!std::regex_match(input, std::regex("(\\s)*(\\d)+((\\\\)|(/)|(-))(\\d)+((\\\\)|(/)|(-))(\\d)+(\\s)+(\\d)+(\\s)+(\\d)+(\\s)*")))
        {
            v.inputError();
        }
        else
        {
            // Capture the info and send it to the model.
            int day, month, year;
            int small, big;
            char slash;

            std::stringstream temp(input);
            temp >> day >> slash >> month >> slash >> year >> small >> big;

            std::pair<std::string, double> result = m.computeCheaper(day, month, year, small, big);

            // Return the result to the view.
            v.outputResult(result.first, result.second);
        }
    }
}