/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** NetworkModule.hpp
*/

#ifndef NETWORK_MODULE_HPP
#define NETWORK_MODULE_HPP

/*============================================================================*/
/* Include */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "IMonitorModule.hpp"

/*============================================================================*/
/* Class */

class NetworkModule : public IMonitorModule
{
    public:
        NetworkModule(void);
        ~NetworkModule(void);

        void updateInfo(void) override;
        bool getActivity(void) const override;
        void setActivity(bool) override;
        const std::vector<long> &getReceive(void) const;
        const std::vector<long> &getTransmit(void) const;
    protected:
        bool _activity;
        std::vector<long> bytes_receive;
        std::vector<long> bytes_transmit;
};

/*============================================================================*/
#endif /* !NETWORK_MODULE_HPP */