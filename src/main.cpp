/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** main.cpp
*/

/*============================================================================*/
/* Include */

#include <string>
#include <iostream>

#include "MonitorDisplay.hpp"
#include "SFML.hpp"
#include "InitNcurses.hpp"

/*============================================================================*/
/* Main */

int main(int argc, char *argv[])
{
    MonitorDisplay monitor;

    if (argc != 2) {
        std::cout << "./MyGKrellm [-t | -g]" << std::endl;
        std::cout << "\t[-t] for terminal version." << std::endl;
        std::cout << "\t[-g] for graphical version." << std::endl;
        return (84);
    }
    monitor.updateModule();
    if ((std::string)argv[1] == "-t") {
        curse::init(&monitor);
    }
    if ((std::string)argv[1] == "-g") {
        Visual::init(&monitor);
    }
    return (0);
}

/*============================================================================*/