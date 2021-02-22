/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** DateModule.cpp
*/

/*============================================================================*/
/* Include */

#include "DateModule.hpp"

/*============================================================================*/
/* Constructor / Destructor */

DateModule::DateModule(void)
{
    this->_activity = false;
}

/*----------------------------------------------------------------------------*/

DateModule::~DateModule(void)
{
}

/*============================================================================*/
/* Functions */

void DateModule::updateInfo(void)
{
    if (this->_activity) {
        return;
    }
    std::chrono::_V2::system_clock::time_point start = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(start);

    this->time = std::ctime(&end_time);
}

/*----------------------------------------------------------------------------*/

bool DateModule::getActivity(void) const
{
    return (this->_activity);
}

/*----------------------------------------------------------------------------*/

void DateModule::setActivity(bool activity)
{
    this->_activity = activity;
}

/*----------------------------------------------------------------------------*/

std::string DateModule::getTime(void) const
{
    return this->time;
}

/*============================================================================*/