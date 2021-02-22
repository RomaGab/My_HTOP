/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** InitNcurses.cpp
*/

/*============================================================================*/
/* Include */

#include "InitNcurses.hpp"

/*============================================================================*/
/* Constructor / Destructor */

curse::curse()
{
    this->x = 0;
    this->y = 0;
    initscr();
    nodelay(stdscr, true);
    noecho();
    cbreak();
    keypad(stdscr, true);
    curs_set(FALSE);
}

/*----------------------------------------------------------------------------*/

curse::~curse()
{
    echo();
    curs_set(TRUE);
    endwin();
}

/*============================================================================*/
/* Functions */

void curse::init(MonitorDisplay *monitor)
{
    curse c;

    c.setMonitor(monitor);
    int move = 0;

    while (1) {
        c.display_loop();
        move = getch();
        if (move == 'q')
            break;
        c.monitor->updateModule();
    }
    c.~curse();
}

/*----------------------------------------------------------------------------*/

void display_hostname(std::string host, std::string user, int *y, int *x)
{
    host = "The host is " + host;
    user = "The user is " + user;
    mvaddstr(*y, *x, host.data());
    mvaddstr(*y + 1, *x, user.data());
    *y += 3;
}

/*----------------------------------------------------------------------------*/

void display_op_sys(std::string osName, std::string kernelVersion, int *y, int *x)
{
    osName = "The current OS is : " + osName;
    kernelVersion = "The current kernel version is : " + kernelVersion;
    mvaddstr(*y, *x, osName.data());
    mvaddstr(*y + 1, *x, kernelVersion.data());
    *y += 3;
}

/*----------------------------------------------------------------------------*/

void display_date(std::string time, int *y, int *x)
{
    time = "The date is : " + time;
    mvaddstr(*y, *x, time.data());
    *y += 2;
}

/*----------------------------------------------------------------------------*/

void display_nb_core(int nb_core, int *y, int *x)
{
    std::string str;

    str = "Numbers of Cpu(s) used: " + std::to_string(nb_core);
    mvaddstr(*y, *x, str.data());
    *y += 2;
}

/*----------------------------------------------------------------------------*/

void display_model_core(int *y, int *x, std::string model)
{
    std::ifstream fd;

    model = "Cpu model is : " + model;
    mvaddstr(*y, *x, model.data());
    *y += 2;
}

/*----------------------------------------------------------------------------*/

void display_Ram(unsigned long total, unsigned long free, int *y, int *x)
{
    long used = total - free;
    std::string str = "Mem Used : " + std::to_string(used) + " / " + std::to_string(total) + " Mo";
    mvaddstr(*y, *x, str.data());
    *y += 1;
}

/*----------------------------------------------------------------------------*/

void display_Swap(unsigned long total, unsigned long free, int *y, int *x)
{
    long used = total - free;
    std::string str = "Swap Used : " + std::to_string(used) + " / " + std::to_string(total) + " Mo";
    mvaddstr(*y, *x, str.data());
    *y += 1;
}

/*----------------------------------------------------------------------------*/

void display_Network(long bytes_re, long bytes_tr, int *y, int *x)
{
    std::string str1 = "Receives : " + std::to_string(bytes_re) + " Bytes";
    std::string str2 = "Transmits : " + std::to_string(bytes_tr) + " Bytes";
    mvaddstr(*y, *x, str1.data());
    mvaddstr(*y + 1, *x, str2.data());
    *y += 3;
}

/*----------------------------------------------------------------------------*/

void display_core(int *y, int *x, double usage)
{
    double results[3];
    std::string str;
    int nb_barre = 0;

    if (getloadavg(results, 3) == 3) {
        str += "%CPU(s): [";
        while (nb_barre < usage) {
            str += "|";
            nb_barre += 1;
        }
        while (nb_barre < 100) {
            str += " ";
            nb_barre += 1;
        }
        str += std::to_string(usage);
        str += "%]";
        mvaddstr(*y, *x, str.data());
        *y += 2;
    }
}

/*----------------------------------------------------------------------------*/

void curse::display_loop()
{
    erase();
    this->x = 0;
    this->y = 0;

    mvaddstr(this->y, COLS/2 - 9, "MyGKrellm");
    this->y += 2;
    display_date(this->monitor->getDate()->getTime(), &this->y, &this->x);
    display_hostname(this->monitor->getName()->getHost(), this->monitor->getName()->getUser(), &this->y, &this->x);
    display_op_sys(this->monitor->getOs()->getOsName(), this->monitor->getOs()->getKernelVersion(), &this->y, &this->x);
    display_nb_core(this->monitor->getCpu()->getNbCore(), &this->y, &this->x);
    display_model_core(&this->y, &this->x, this->monitor->getCpu()->getModel());
    display_Ram(this->monitor->getRam()->getTotalRam(), this->monitor->getRam()->getFreeRam(), &this->y, &this->x);
    display_Swap(this->monitor->getRam()->getTotalSwap(), this->monitor->getRam()->getFreeSwap(), &this->y, &this->x);
    display_Network(this->monitor->getNetwork()->getReceive()[0], this->monitor->getNetwork()->getTransmit()[0], &this->y, &this->x);
    display_core(&this->y, &this->x, this->monitor->getCpu()->getLastUsage());
    refresh();
}

/*----------------------------------------------------------------------------*/

void curse::setMonitor(MonitorDisplay *monitor)
{
    this->monitor = monitor;
}

/*============================================================================*/