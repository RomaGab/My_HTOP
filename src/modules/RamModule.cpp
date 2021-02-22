/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** RamModule.cpp
*/

/*============================================================================*/
/* Include */

#include <sstream>
#include <fstream>

#include <sys/sysinfo.h>

#include "RamModule.hpp"

/*============================================================================*/
/* Constructor / Destructor */

RamModule::RamModule(void)
{
    this->_activity = false;
}

/*----------------------------------------------------------------------------*/

RamModule::~RamModule(void)
{
}

/*============================================================================*/
/* Functions */

void RamModule::updateInfo(void)
{
    std::ifstream fd;
    std::string line = "";
    std::string name = "";
    unsigned long mem = 0;

    if (this->_activity) {
        return;
    }
    fd.open("/proc/meminfo");
    if (fd.is_open()) {
        while (std::getline(fd, line)) {
            std::stringstream(line) >> name >> mem;
            if (name == "MemTotal:") {
                this->_totalRam = mem / 1024;
            } else if (name == "MemAvailable:") {
                this->_freeRam = mem / 1024;
            } else if (name == "SwapTotal:") {
                this->_totalSwap = mem / 1024;
            } else if (name == "SwapFree:") {
                this->_freeSwap = mem / 1024;
            }
        }
    }
}

/*----------------------------------------------------------------------------*/

bool RamModule::getActivity(void) const
{
    return (this->_activity);
}

/*----------------------------------------------------------------------------*/

void RamModule::setActivity(bool activity)
{
    this->_activity = activity;
}

/*----------------------------------------------------------------------------*/

unsigned long RamModule::getTotalRam(void) const
{
    return this->_totalRam;
}

/*----------------------------------------------------------------------------*/

unsigned long RamModule::getFreeRam(void) const
{
    return this->_freeRam;
}

/*----------------------------------------------------------------------------*/

unsigned long RamModule::getTotalSwap(void) const
{
    return this->_totalSwap;
}

/*----------------------------------------------------------------------------*/

unsigned long RamModule::getFreeSwap(void) const
{
    return this->_freeRam;
}

/*============================================================================*/