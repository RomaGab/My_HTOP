/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** InitNcurses.cpp
*/

#ifndef INIT_NCURSES_HPP
#define INIT_NCURSES_HPP

/*============================================================================*/
/* Include */

#include <curses.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sys/sysinfo.h>

#include "MonitorDisplay.hpp"

/*============================================================================*/
/* Class */

class curse
{
    public:
        curse();
        ~curse();
        static void init(MonitorDisplay *monitor);
        void display_loop();
        void setMonitor(MonitorDisplay *monitor);

    private:
        int y;
        int x;
        MonitorDisplay *monitor;
};

/*============================================================================*/
#endif /* !INIT_NCURSES_HPP */