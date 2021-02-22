/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** IMonitorModule.hpp
*/

#ifndef IMONITOR_MODULE_HPP
#define IMONITOR_MODULE_HPP

/*============================================================================*/
/* Include */

#include <string>

/*============================================================================*/
/* Class */

class IMonitorModule
{
    public:
        virtual ~IMonitorModule() = default;

        virtual void updateInfo(void) = 0;
        virtual bool getActivity(void) const = 0;
        virtual void setActivity(bool) = 0;
};

/*============================================================================*/
#endif /* !IMONITOR_MODULE_HPP */