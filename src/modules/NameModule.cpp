/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** NameModule.cpp
*/

/*============================================================================*/
/* Include */

#include "NameModule.hpp"

/*============================================================================*/
/* Constructor / Destructor */

NameModule::NameModule(void)
{
    this->_activity = false;
}

/*----------------------------------------------------------------------------*/

NameModule::~NameModule(void)
{
}

/*============================================================================*/
/* Functions */

void NameModule::updateInfo(void)
{
    if (this->_activity) {
        return;
    }
    this->_host = getenv("HOSTNAME");
    this->_user = getenv("USER");
}

/*----------------------------------------------------------------------------*/

bool NameModule::getActivity(void) const
{
    return (this->_activity);
}

/*----------------------------------------------------------------------------*/

void NameModule::setActivity(bool activity)
{
    this->_activity = activity;
}

/*----------------------------------------------------------------------------*/

std::string NameModule::getUser(void) const
{
    return this->_user;
}

/*----------------------------------------------------------------------------*/

std::string NameModule::getHost(void) const
{
    return this->_host;
}

/*============================================================================*/