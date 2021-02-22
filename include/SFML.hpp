/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** SFML.hpp
*/

#ifndef SFML_HPP
#define SFML_HPP

/*============================================================================*/
/* Include */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "MonitorDisplay.hpp"

#define ESCAPE  sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
#define CLOSE   v.ev.type == sf::Event::Closed

/*============================================================================*/
/* Class */

class Visual
{
    public:
        Visual();
        ~Visual();
        static int init(MonitorDisplay *monitor);
        int check();
        void draw();
        void update();
        void cadre(int or_x, float &or_y, int length, int width, bool click = 0);
        void frame(int or_x, int or_y, int length, int width);
        void graphic(std::vector<long> size, int or_x, int or_y, int length, int width, sf::Color color);
        void graphic(std::vector<double> size, int or_x, int or_y, int length, int width);
        void setMonitor(MonitorDisplay *monitor);
        void checkEv(sf::Event ev);
        void checkHide(sf::Event ev, IMonitorModule *module, int x, int y);
        void displayModules(void);
        void displayName(float &ordY);
        void displayDate(float &ordY);
        void displayOs(float &ordY);
        void displayCPU(float &ordY);
        void displayRam(float &ordY);
        void displayNetwork(float &ordY);
        void displayButton(IMonitorModule *module, int x, int y, const std::string &name);

    private:
        sf::RenderWindow win;
        sf::Texture text;
        sf::Sprite spr;
        sf::Font fnt;
        sf::Text txt;
        sf::Event ev;
        sf::Clock cl;
        sf::Time ti;
        sf::IntRect rect;

        MonitorDisplay *monitor;
        float posx;
        float posy;
        float size;
        int click;
};

/*============================================================================*/
#endif /* !SFML_HPP */