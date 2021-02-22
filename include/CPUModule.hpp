/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** CPUModule.hpp
*/

#ifndef CPU_MODULE_HPP
#define CPU_MODULE_HPP

/*============================================================================*/
/* Include */

#include <string>
#include <iostream>
#include <sys/sysinfo.h>
#include <vector>

#include "IMonitorModule.hpp"

/*============================================================================*/
/* Class */

class CPUModule : public IMonitorModule
{
    public:
        CPUModule(void);
        ~CPUModule(void);

        void updateInfo(void) override;
        bool getActivity(void) const override;
        void setActivity(bool) override;
        std::string getModel(void) const;
        int getNbCore(void) const;
        double getLastUsage(void) const;
        const std::vector<double> &getUsages(void) const;

    protected:
        bool _activity;
        std::string _model;
        int _nbCores;
        double _lastUsage;
        std::vector<double> _usages;
};

/*============================================================================*/
#endif /* !CPU_MODULE_HPP */