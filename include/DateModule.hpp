/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** DateModule.hpp
*/

#ifndef DATE_MODULE_HPP
#define DATE_MODULE_HPP

/*============================================================================*/
/* Include */

#include <string>
#include <iostream>
#include <sys/sysinfo.h>
#include <ctime>
#include <chrono>

#include "IMonitorModule.hpp"

/*============================================================================*/
/* Class */

class DateModule : public IMonitorModule
{
    public:
        DateModule(void);
        ~DateModule(void);

        void updateInfo(void) override;
        bool getActivity(void) const override;
        void setActivity(bool) override;
        std::string getTime(void) const;

    protected:
        bool _activity;
        std::string time;
};

/*============================================================================*/
#endif /* !DATE_MODULE_HPP */