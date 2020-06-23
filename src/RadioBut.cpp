#ifndef H_RADIO
#define H_RADIO
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;
class radio {
private:
    int menuNum = 0;

public:
    radio()
    {
    }
    radio(int a)
    {
        menuNumSet(a);
    }
    void menuNumSet(int Value)
    {
        menuNum = Value;
    }

    int menuNumGet()
    {
        return menuNum;
    }

    int
    draw(int x1,
         int y1,
         int y2,
         int y3,
         RenderWindow& window,
         bool CheckPosition)
    {
        Texture RadButtonTexture;
        RadButtonTexture.loadFromFile("image/rad.png");
        Sprite but1(RadButtonTexture), but2(RadButtonTexture),
                but3(RadButtonTexture);
        but1.setPosition(x1, y1);
        but2.setPosition(x1, y2);
        but3.setPosition(x1, y3);
        if (Mouse::isButtonPressed(Mouse::Left) or CheckPosition) {
            if (IntRect(x1, y1, 47, 47).contains(Mouse::getPosition(window))) {
                menuNumSet(1);
            }
            if (IntRect(x1, y2, 47, 47).contains(Mouse::getPosition(window))) {
                menuNumSet(2);
            }
            if (IntRect(x1, y3, 47, 47).contains(Mouse::getPosition(window))) {
                menuNumSet(3);
            }
        }

        if (menuNumGet() == 1) {
            but1.setColor(Color::Red);
            but2.setColor(Color::White);
            but3.setColor(Color::White);
        }
        if (menuNumGet() == 2) {
            but2.setColor(Color::Red);
            but1.setColor(Color::White);
            but3.setColor(Color::White);
        }
        if (menuNumGet() == 3) {
            but3.setColor(Color::Red);
            but1.setColor(Color::White);
            but2.setColor(Color::White);
        }

        window.draw(but1);
        window.draw(but2);
        window.draw(but3);
        return menuNumGet();
    }
};
#endif
