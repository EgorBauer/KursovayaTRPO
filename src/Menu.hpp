#ifndef H_MENU
#define H_MENU
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;
void menu(RenderWindow& window);
void dev(
        RenderWindow& window,
        Texture& BackgroundDevelopersTexture,
        Texture& ButtonExitTexture,
        Texture& ButtonBackTexture);
void inter(
        RenderWindow& window,
        Texture& BackgroundInternetTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture);
void mob(
        RenderWindow& window,
        Texture& BackgroundMobileTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture);
void telev(
        RenderWindow& window,
        Texture& BackgroundTvTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture);
void result(
        RenderWindow& window,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture,
        Texture& ButtonBackTexture);

#endif
