/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** NameModule.hpp
*/

#ifndef NAME_MODULE_HPP
#define NAME_MODULE_HPP

/*============================================================================*/
/* Include */

#include "IMonitorModule.hpp"

/*============================================================================*/
/* Class */

class NameModule : public IMonitorModule
{
    public:
        NameModule(void);
        ~NameModule(void);

        void updateInfo(void) override;
        bool getActivity(void) const override;
        void setActivity(bool) override;
        std::string getUser(void) const;
        std::string getHost(void) const;

    protected:
        bool _activity;
        std::string _user;
        std::string _host;
};

/*============================================================================*/
#endif /* !NAME_MODULE_HPP */