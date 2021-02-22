/*
** EPITECH PROJECT, 2020
** My_HTOP
** File description:
** main.cpp
*/

/*============================================================================*/
/* Include / Define */

#include "SFML.hpp"

/*============================================================================*/
/* Constructor / Destructor */

Visual::Visual() : win(sf::VideoMode(456, 800), "ZZTop", sf::Style::Titlebar | sf::Style::Close), txt("", this->fnt, 20), ti(sf::seconds(1.0f))
{
    this->posx = 800;
    this->posy = 600;
    this->size = 100;
    this->win.setFramerateLimit(180);
    this->ti = this->cl.getElapsedTime();
    this->txt.setPosition(sf::Vector2f(60, 2));
    this->spr.setPosition(sf::Vector2f(4, 6));
    this->rect = {0, 0, 50, 20};
    this->spr.setTextureRect(this->rect);
    this->click = 0;
}

/*----------------------------------------------------------------------------*/

Visual::~Visual()
{
    ;
}

/*============================================================================*/
/* Functions */

void Visual::graphic(std::vector<long> size, int or_x, int or_y, int length, int width, sf::Color color)
{
    sf::RectangleShape rectangle(sf::Vector2f(2.f, 1));
    std::vector<long>::iterator it = size.end();
    float posx = or_x + 1 + length;
    float posy = or_y + 3.5 + width;
    float high = 0.;

    if (it == size.begin()) {
        return;
    }
    for (it--; true; it--) {
        rectangle.setFillColor(color);
        rectangle.setOutlineColor(sf::Color(200, 200, 200));
        high = (long)*it * 200 / 300000000;
        if (high > 200) {
            high = 200;
        }
        rectangle.setSize(sf::Vector2f(3.f, high));
        rectangle.setOrigin((sf::Vector2f(0, high)));
        rectangle.setPosition(sf::Vector2f(posx, posy));
        posx -= 4;
        if (posx >= -1)
            this->win.draw(rectangle);
        if (it == size.begin()) {
            break;
        }
    }
}

/*----------------------------------------------------------------------------*/

void Visual::graphic(std::vector<double> size, int or_x, int or_y, int length, int width)
{
    sf::RectangleShape rectangle(sf::Vector2f(2.f, 1));
    std::vector<double>::iterator it = size.end();
    float posx = or_x + 1 + length;
    float posy = or_y + 3.5 + width;
    float high = 0.;

    if (it == size.begin()) {
        return;
    }
    for (it--; true; it--) {
        rectangle.setFillColor(sf::Color::Green);
        rectangle.setOutlineColor(sf::Color(200, 200, 200));
        high = (float)*it * 200 / 100;
        if (high > 200) {
            high = 200;
        }
        rectangle.setSize(sf::Vector2f(3.f, high));
        rectangle.setOrigin((sf::Vector2f(0, high)));
        rectangle.setPosition(sf::Vector2f(posx, posy));
        posx -= 4;
        if (posx >= -1)
            this->win.draw(rectangle);
        if (it == size.begin()) {
            break;
        }
    }
}

/*----------------------------------------------------------------------------*/

void Visual::update()
{
    this->win.clear();
    this->ti = this->cl.getElapsedTime();
    if (this->ti.asSeconds() >= 1) {
        this->monitor->updateModule();
        this->cl.restart();
    };
}

/*----------------------------------------------------------------------------*/

void Visual::cadre(int or_x, float &or_y, int length, int width, bool click)
{
    sf::RectangleShape rectangle(sf::Vector2f(length, width));
    rectangle.setSize(sf::Vector2f(length, width));
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color(119, 136, 153));
    rectangle.setOutlineThickness(1);
    rectangle.setOrigin((sf::Vector2f(-3, -3)));
    rectangle.setPosition(sf::Vector2f(or_x, or_y));
    if (click == 1) {
        rectangle.setSize(sf::Vector2f(length, 26));
        or_y += 26 + 4;
    } else {
        or_y += width + 4;
    }
    this->win.draw(rectangle);
}

/*----------------------------------------------------------------------------*/

void Visual::checkHide(sf::Event ev, IMonitorModule *module, int x, int y)
{
    if (ev.mouseButton.x >= x && ev.mouseButton.x <= (x + this->rect.width)
    && ev.mouseButton.y >= y && ev.mouseButton.y <= (y + this->rect.height)) {
        if (!module->getActivity()) {
            module->setActivity(1);
        } else {
            module->setActivity(0);
        }
    }
}

/*----------------------------------------------------------------------------*/

void Visual::checkEv(sf::Event ev)
{
    if (ev.type == sf::Event::MouseButtonPressed) {
        checkHide(ev, this->monitor->getName(), 10, 10);
        checkHide(ev, this->monitor->getDate(), 160, 10);
        checkHide(ev, this->monitor->getOs(), 310, 10);
        checkHide(ev, this->monitor->getCpu(), 10, 40);
        checkHide(ev, this->monitor->getRam(), 160, 40);
        checkHide(ev, this->monitor->getNetwork(), 310, 40);
    }
}

/*----------------------------------------------------------------------------*/

void Visual::draw()
{
    this->update();
    this->win.clear();
    this->displayModules();
    this->win.display();
}

/*----------------------------------------------------------------------------*/

int Visual::check()
{
    if (!this->text.loadFromFile("res/button.png"))
        return 84;
    this->spr.setTexture(this->text);
    if (!this->fnt.loadFromFile("res/font.ttf"))
        return 84;
    return 0;
}

/*----------------------------------------------------------------------------*/

int Visual::init(MonitorDisplay *monitor)
{
    Visual v;

    v.setMonitor(monitor);
    if (v.check() != 0)
        return 84;
    while (v.win.isOpen()) {
        while (v.win.pollEvent(v.ev)) {
            v.checkEv(v.ev);
            if (CLOSE || ESCAPE)
                v.win.close();
        } v.draw();
    } return 0;
}

/*----------------------------------------------------------------------------*/

void Visual::setMonitor(MonitorDisplay *monitor)
{
    this->monitor = monitor;
}

/*----------------------------------------------------------------------------*/

void Visual::displayModules(void)
{
    float ordY = 0;

    this->cadre(0, ordY, 450, 65);
    this->displayName(ordY);
    this->displayOs(ordY);
    this->displayDate(ordY);
    this->displayCPU(ordY);
    this->displayRam(ordY);
    this->displayNetwork(ordY);
    sf::FloatRect visibleArea(0, 0, 456, ordY);
    this->win.setView(sf::View(visibleArea));
    this->win.setSize(sf::Vector2u(456, ordY));
}

/*----------------------------------------------------------------------------*/

void Visual::displayButton(IMonitorModule *module, int x, int y, const std::string &name)
{
    this->rect.top = 0;
    if (module->getActivity()) {
        this->rect.top = 20;
    }
    this->spr.setTextureRect(this->rect);
    this->spr.setPosition(x, y);
    this->win.draw(this->spr);
    this->txt.setPosition(x + 60, y - 3);
    this->txt.setString(name);
    this->win.draw(this->txt);
}

/*----------------------------------------------------------------------------*/

void Visual::displayName(float &ordY)
{
    NameModule *name = this->monitor->getName();

    this->displayButton(name, 10, 10, ": Name");
    if (name->getActivity()) {
        return;
    }
    this->txt.setPosition(10, ordY + 2);
    this->txt.setString("User: " + name->getUser());
    this->win.draw(this->txt);
    this->txt.setPosition(10, ordY + 27);
    this->txt.setString("Host: " + name->getHost());
    this->win.draw(this->txt);
    this->cadre(0, ordY, 450, 50);
}

/*----------------------------------------------------------------------------*/

void Visual::displayDate(float &ordY)
{
    DateModule *date = this->monitor->getDate();

    this->displayButton(date, 160, 10, ": Date");
    if (date->getActivity()) {
        return;
    }
    this->txt.setPosition(10, ordY + 2);
    this->txt.setString("Date: " + date->getTime());
    this->win.draw(this->txt);
    this->cadre(0, ordY, 450, 25);
}

/*----------------------------------------------------------------------------*/

void Visual::displayOs(float &ordY)
{
    OSModule *os = this->monitor->getOs();

    this->displayButton(os, 310, 10, ": OS");
    if (os->getActivity()) {
        return;
    }
    this->txt.setPosition(10, ordY + 2);
    this->txt.setString("OS: " + os->getOsName());
    this->win.draw(this->txt);
    this->txt.setPosition(10, ordY + 27);
    this->txt.setString("Version: " + os->getKernelVersion());
    this->win.draw(this->txt);
    this->cadre(0, ordY, 450, 50);
}

/*----------------------------------------------------------------------------*/

void Visual::displayCPU(float &ordY)
{
    CPUModule *cpu = this->monitor->getCpu();

    this->displayButton(cpu, 10, 40, ": CPU");
    if (cpu->getActivity()) {
        return;
    }
    this->graphic(cpu->getUsages(), 0, ordY, 450, 200);
    this->txt.setPosition(10, ordY + 2);
    this->txt.setString("CPU: " + cpu->getModel());
    this->win.draw(this->txt);
    this->txt.setPosition(10, ordY + 27);
    this->txt.setString("Nb Cores: " + std::to_string(cpu->getNbCore()));
    this->win.draw(this->txt);
    this->cadre(0, ordY, 450, 200, cpu->getActivity());
}

/*----------------------------------------------------------------------------*/

void Visual::displayRam(float &ordY)
{
    RamModule *ram = this->monitor->getRam();

    this->displayButton(ram, 160, 40, ": Ram");
    if (ram->getActivity()) {
        return;
    }
    long usedRam = ram->getTotalRam() - ram->getFreeRam();
    long usedSwap = ram->getTotalSwap() - ram->getFreeSwap();
    std::string Ram = std::to_string(usedRam) + " / " + "" + std::to_string(ram->getTotalRam()) + " Mo";
    std::string Swap = std::to_string(usedSwap) + " / " + "" + std::to_string(ram->getTotalSwap()) + " Mo";


    this->txt.setPosition(10, ordY + 2);
    this->txt.setString("RAM: " + Ram);
    this->win.draw(this->txt);
    this->txt.setPosition(10, ordY + 27);
    this->txt.setString("SWAP: " + Swap);
    this->win.draw(this->txt);
    this->cadre(0, ordY, 450, 50);
}

/*----------------------------------------------------------------------------*/

void Visual::displayNetwork(float &ordY)
{
    NetworkModule *network = this->monitor->getNetwork();

    this->displayButton(network, 310, 40, ": Network");
    if (network->getActivity()) {
        return;
    }
    this->graphic(network->getReceive(), 0, ordY, 450, 200, sf::Color::Green);
    this->graphic(network->getTransmit(), 0, ordY, 450, 200, sf::Color::Red);
    this->txt.setPosition(10, ordY + 2);
    this->txt.setString("Network: ");
    this->win.draw(this->txt);
    this->cadre(0, ordY, 450, 200);
}

/*============================================================================*/