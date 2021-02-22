/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** IMonitorDisplay.cpp
*/

/*============================================================================*/
/* Include */

#include "MonitorDisplay.hpp"

/*============================================================================*/
/* Constructor / Destructor */

MonitorDisplay::MonitorDisplay(void)
{
    this->d_type = NOTHING;
    this->_name = new NameModule;
    this->_date = new DateModule;
    this->_os = new OSModule;
    this->_cpu = new CPUModule;
    this->_ram = new RamModule;
    this->_network = new NetworkModule;
}

/*----------------------------------------------------------------------------*/

MonitorDisplay::~MonitorDisplay(void)
{
    delete this->_name;
    delete this->_date;
    delete this->_os;
    delete this->_cpu;
    delete this->_ram;
    delete this->_network;
}

/*============================================================================*/
/* Functions */

NameModule *MonitorDisplay::getName(void) const
{
    return (this->_name);
}

/*----------------------------------------------------------------------------*/

OSModule *MonitorDisplay::getOs(void) const
{
    return (this->_os);
}

/*----------------------------------------------------------------------------*/

DateModule *MonitorDisplay::getDate(void) const
{
    return (this->_date);
}

/*----------------------------------------------------------------------------*/

CPUModule *MonitorDisplay::getCpu(void) const
{
    return (this->_cpu);
}

/*----------------------------------------------------------------------------*/

RamModule *MonitorDisplay::getRam(void) const
{
    return (this->_ram);
}

/*----------------------------------------------------------------------------*/

NetworkModule *MonitorDisplay::getNetwork(void) const
{
    return (this->_network);
}

/*----------------------------------------------------------------------------*/

void MonitorDisplay::setName(NameModule *name)
{
    this->_name = name;
}

/*----------------------------------------------------------------------------*/

void MonitorDisplay::setOs(OSModule *os)
{
    this->_os = os;
}

/*----------------------------------------------------------------------------*/

void MonitorDisplay::setDate(DateModule *date)
{
    this->_date = date;
}

/*----------------------------------------------------------------------------*/

void MonitorDisplay::setCpu(CPUModule *cpu)
{
    this->_cpu = cpu;
}

/*----------------------------------------------------------------------------*/

void MonitorDisplay::setRam(RamModule *ram)
{
    this->_ram = ram;
}

/*----------------------------------------------------------------------------*/

void MonitorDisplay::setNetwork(NetworkModule *network)
{
    this->_network = network;
}

/*----------------------------------------------------------------------------*/

void MonitorDisplay::updateModule(void)
{
    this->_name->updateInfo();
    this->_os->updateInfo();
    this->_date->updateInfo();
    this->_cpu->updateInfo();
    this->_ram->updateInfo();
    this->_network->updateInfo();
}

/*============================================================================*/