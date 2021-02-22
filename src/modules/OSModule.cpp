/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** OSModule.cpp
*/

/*============================================================================*/
/* Include */

#include "OSModule.hpp"

/*============================================================================*/
/* Constructor / Destructor */

OSModule::OSModule(void)
{
    this->_activity = false;
}

/*----------------------------------------------------------------------------*/

OSModule::~OSModule(void)
{
}

/*============================================================================*/
/* Functions */

void OSModule::updateInfo(void)
{
    struct utsname version;

    if (this->_activity) {
        return;
    }
    uname(&version);
    this->_osName = version.sysname;
    this->_kernelVersion = version.release;
}

/*----------------------------------------------------------------------------*/

bool OSModule::getActivity(void) const
{
    return (this->_activity);
}

/*----------------------------------------------------------------------------*/

void OSModule::setActivity(bool activity)
{
    this->_activity = activity;
}

/*----------------------------------------------------------------------------*/

std::string OSModule::getOsName(void) const
{
    return this->_osName;
}

/*----------------------------------------------------------------------------*/

std::string OSModule::getKernelVersion(void) const
{
    return this->_kernelVersion;
}

/*============================================================================*/