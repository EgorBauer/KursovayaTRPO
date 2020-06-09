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
        Texture& ButtonCountTexture);
void mob(
        RenderWindow& window,
        Texture& BackgroundMobileTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture);
void telev(
        RenderWindow& window,
        Texture& BackgroundTvTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture);
#endif
