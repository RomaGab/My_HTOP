/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** OSModule.hpp
*/

#ifndef OS_MODULE_HPP
#define OS_MODULE_HPP

/*============================================================================*/
/* Include */

#include <sys/utsname.h>

#include "IMonitorModule.hpp"

/*============================================================================*/
/* Class */

class OSModule : public IMonitorModule
{
    public:
        OSModule(void);
        ~OSModule(void);

        void updateInfo(void) override;
        bool getActivity(void) const override;
        void setActivity(bool) override;
        std::string getOsName(void) const;
        std::string getKernelVersion(void) const;

    protected:
        bool _activity;
        std::string _osName;
        std::string _kernelVersion;
};

/*============================================================================*/
#endif /* !OS_MODULE_HPP */