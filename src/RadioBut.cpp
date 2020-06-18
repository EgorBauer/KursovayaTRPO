#ifndef H_RADIO
#define H_RADIO
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class radio {
private:
    int menuNum = 0;

public:
    void menuNumSet(int Value)
    {
        menuNum = Value;
    }

    int menuNumGet()
    {
        return menuNum;
    }

    int draw(int x1, int x2, int x3, int y1, int y2, int y3)
    {
        Texture RadButtonTexture;
        RadButtonTexture.loadFromFile("image/rad.png");
        Sprite but1(RadButtonTexture), but2(RadButtonTexture),
                but3(RadButtonTexture);
        but1.setPosition(x1, y1);
        but2.setPosition(x2, y2);
        but3.setPosition(x3, y3);

        window.draw(but1);
        window.draw(but2);
        window.draw(but3);
    }
}
#endif
