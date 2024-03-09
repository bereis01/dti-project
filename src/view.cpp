#include "view.hpp"

void View::title()
{
    std::cout << "  ######   ######  ######   #####  ##   #    ####    ###### " << std::endl;
    std::cout << "  ##    #  ##        ##    ##      ##   #   ##   #   ##    #" << std::endl;
    std::cout << "  ##    #  ####      ##    ####    ######  ##     #  ##    #" << std::endl;
    std::cout << "  ######   ####      ##      ####  ######  ##     #  ###### " << std::endl;
    std::cout << "  ##       ##        ##        ##  ##   #   ##   #   ##     " << std::endl;
    std::cout << "  ##       ######    ##    #####   ##   #    ####    ##     " << std::endl;
    std::cout << "  ##########################################################" << std::endl;
    std::cout << "  ######################################################v1.0" << std::endl;
    std::cout << "                                                            " << std::endl;
    std::cout << "  Welcome back, Mr. Eduardo!                                " << std::endl
              << std::endl;
}

void View::instructions()
{
    std::cout << "  Please, input information in the following format: DD/MM/YYYY S B" << std::endl;
    std::cout << "  Press (ENTER) to exit at anytime." << std::endl
              << std::endl;
}

void View::inputLayer()
{
    std::cout << "  > ";
    std::cin.getline(input, sizeof(input));
    std::cout << std::endl;
}

void View::inputError()
{
    std::cout << "  Incorrect input format. Please, try again." << std::endl
              << std::endl;
}

void View::outputResult(std::string name, double value)
{
    std::cout << "  The cheapest PetShop is " << name << " with a price of R$"
              << std::fixed << std::setprecision(2) << value << "." << std::endl
              << std::endl;
}