/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** CPUModule.cpp
*/

/*============================================================================*/
/* Include */

#include <fstream>

#include "CPUModule.hpp"

/*============================================================================*/
/* Constructor / Destructor */

CPUModule::CPUModule(void)
{
    this->_activity = false;
}

/*----------------------------------------------------------------------------*/

CPUModule::~CPUModule(void)
{
}

/*============================================================================*/
/* Functions */

void CPUModule::updateInfo(void)
{
    double results[3];
    int nbCores = (double)get_nprocs();
    std::ifstream fd;
    std::string str;
    int i = 0;

    if (this->_activity) {
        return;
    }
    this->_nbCores = nbCores;
    if (getloadavg(results, 3) == 3) {
        this->_lastUsage = results[0] / nbCores * 100;
        this->_usages.push_back(results[0] / nbCores * 100);
    }
    fd.open("/proc/cpuinfo");
    if (fd.is_open()) {
        while (i < 5) {
            std::getline(fd, str);
            i += 1;
        }
        this->_model = &str[13];
        fd.close();
    }
    if (this->_usages.size() == 120) {
        this->_usages.erase(this->_usages.begin());
    }
}

/*----------------------------------------------------------------------------*/

bool CPUModule::getActivity(void) const
{
    return (this->_activity);
}

/*----------------------------------------------------------------------------*/

void CPUModule::setActivity(bool activity)
{
    this->_activity = activity;
    if (activity == false) {
        this->_usages.clear();
    }
}

/*----------------------------------------------------------------------------*/

std::string CPUModule::getModel(void) const
{
    return (this->_model);
}

/*----------------------------------------------------------------------------*/

int CPUModule::getNbCore(void) const
{
    return (this->_nbCores);
}

/*----------------------------------------------------------------------------*/

double CPUModule::getLastUsage(void) const
{
    return (this->_lastUsage);
}

/*----------------------------------------------------------------------------*/

const std::vector<double> &CPUModule::getUsages(void) const
{
    return (this->_usages);
}

/*============================================================================*/