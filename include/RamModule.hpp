/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** RamModule.hpp
*/

#ifndef RAM_MODULE_HPP
#define RAM_MODULE_HPP

/*============================================================================*/
/* Include */

#include <string>
#include <iostream>
#include <sys/sysinfo.h>

#include "IMonitorModule.hpp"

/*============================================================================*/
/* Class */

class RamModule : public IMonitorModule
{
    public:
        RamModule(void);
        ~RamModule(void);

        void updateInfo(void) override;
        bool getActivity(void) const override;
        void setActivity(bool) override;
        unsigned long getTotalRam(void) const;
        unsigned long getFreeRam(void) const;
        unsigned long getTotalSwap(void) const;
        unsigned long getFreeSwap(void) const;

    protected:
        bool _activity;
        unsigned long _totalRam;
        unsigned long _freeRam;
        unsigned long _totalSwap;
        unsigned long _freeSwap;
};

/*============================================================================*/
#endif /* !RAM_MODULE_HPP */