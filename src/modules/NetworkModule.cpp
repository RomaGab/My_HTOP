/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** NetworkModule.cpp
*/

/*============================================================================*/
/* Include */

#include "NetworkModule.hpp"

/*============================================================================*/
/* Constructor / Destructor */

NetworkModule::NetworkModule(void)
{
    this->_activity = false;
}

/*----------------------------------------------------------------------------*/

NetworkModule::~NetworkModule(void)
{
}

/*============================================================================*/
/* Functions */

void NetworkModule::updateInfo(void)
{
    std::ifstream filename;
    std::string name = "";
    std::string bytes_receive = "";
    std::string bytes_transmit = "";
    std::string line = "";
    std::string tmp = "";
    long re = 0;
    long tr = 0;

    if (this->_activity) {
        return;
    }
    filename.open("/proc/net/dev");
    while (std::getline(filename, line)) {
        if (line.find(':', 0) != (size_t)-1) {
            std::stringstream(line) >> name >> bytes_receive >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> bytes_transmit;
            re += stol(bytes_receive);
            tr += stol(bytes_transmit);
        }
    }
    this->bytes_receive.push_back(re);
    this->bytes_transmit.push_back(tr);
    if (this->bytes_receive.size() == 120) {
        this->bytes_receive.erase(this->bytes_receive.begin());
    }
    if (this->bytes_transmit.size() == 120) {
        this->bytes_transmit.erase(this->bytes_transmit.begin());
    }
    filename.close();
}

/*----------------------------------------------------------------------------*/

bool NetworkModule::getActivity(void) const
{
    return (this->_activity);
}

/*----------------------------------------------------------------------------*/

void NetworkModule::setActivity(bool activity)
{
    this->_activity = activity;
    if (activity == false) {
        this->bytes_receive.clear();
        this->bytes_transmit.clear();
    }
}

/*----------------------------------------------------------------------------*/

const std::vector<long> &NetworkModule::getReceive(void) const
{
    return (this->bytes_receive);
}

/*----------------------------------------------------------------------------*/

const std::vector<long> &NetworkModule::getTransmit(void) const
{
    return (this->bytes_transmit);
}

/*============================================================================*/