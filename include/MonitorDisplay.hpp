/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** IMonitorDisplay.hpp
*/

#ifndef MONITOR_DISPLAY_HPP
#define MONITOR_DISPLAY_HPP

/*============================================================================*/
/* Include */

#include <list>

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "NameModule.hpp"
#include "OSModule.hpp"
#include "DateModule.hpp"
#include "CPUModule.hpp"
#include "RamModule.hpp"
#include "NetworkModule.hpp"

/*============================================================================*/
/* Enum */

enum DisplayType
{NOTHING, SFML, NCURSES};

/*============================================================================*/
/* Class */

class MonitorDisplay : public IMonitorDisplay
{
    public:
        MonitorDisplay(void);
        ~MonitorDisplay(void);

        void initGraphicLib();
        void closeGraphicLib();

        void setName(NameModule *name);
        NameModule *getName(void) const;
        void setOs(OSModule *os);
        OSModule *getOs(void) const;
        void setDate(DateModule *date);
        DateModule *getDate(void) const;
        void setCpu(CPUModule *cpu);
        CPUModule *getCpu(void) const;
        void setRam(RamModule *ram);
        RamModule *getRam(void) const;
        void setNetwork(NetworkModule *network);
        NetworkModule *getNetwork(void) const;
        void updateModule(void);

    private:
        DisplayType d_type;
        NameModule *_name;
        OSModule *_os;
        DateModule *_date;
        CPUModule *_cpu;
        RamModule *_ram;
        NetworkModule *_network;
};

/*============================================================================*/
#endif /* !MONITOR_DISPLAY_HPP */