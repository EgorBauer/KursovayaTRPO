#include "Menu.hpp"

bool isMenu = 1;

void menu(RenderWindow& window) // risuem Glavnoe Menu
{
    Texture BackgroundTexture, ButtonInternetTexture, ButtonMobileTexture,
            ButtonTvTexture, ButtonDevelopersTexture, ButtonExitTexture,
            ButtonBackTexture, ButtonCountTexture, BackgroundInternetTexture,
            BackgroundMobileTexture, BackgroundTvTexture,
            BackgroundDevelopersTexture;
    // *Nujno budet dobavit image
    BackgroundTexture.loadFromFile("");
    BackgroundInternetTexture.loadFromFile("");
    BackgroundMobileTexture.loadFromFile("");
    BackgroundTvTexture.loadFromFile("");
    BackgroundDevelopersTexture.loadFromFile("");
    ButtonInternetTexture.loadFromFile("");
    ButtonMobileTexture.loadFromFile("");
    ButtonTvTexture.loadFromFile("");
    ButtonDevelopersTexture.loadFromFile("");
    ButtonExitTexture.loadFromFile("");
    ButtonBackTexture.loadFromFile("");
    ButtonCountTexture.loadFromFile("");

    Sprite background(BackgroudTexture), internet(ButtonInternetTexture),
            mobile(ButtonMobileTexture), tv(ButtonTvTexture),
            develop(ButtonDevelopersTexture), exit(ButtonExitTexture);

    int menuNum = 0; // *Nujno podstavit koordinati knopok
    background.setPosition(0, 0);
    internet.setPosition(0, 0);
    mobile.setPosition(0, 0);
    tv.setPosition(0, 0);
    develop.setPosition(0, 0);
    exit.setPosition(0, 0);

    while (window.isOpen()) {
        internet.setColor(Color::White);
        mobile.setColor(Color::White);
        tv.setColor(Color::White);
        develop.setColor(Color::White);
        exit.setColor(Color::White);

        menuNum = 0; // *Nujno podstavit koordinati knopok dly vseh if
        if (IntRect(0, 0, 0, 0).contains(Mouse::getPosition(window))) {
            internet.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(0, 0, 0, 0).contains(Mouse::getPosition(window))) {
            mobile.setColor(Color::Red);
            menuNum = 2;
        }
        if (IntRect(0, 0, 0, 0).contains(Mouse::getPosition(window))) {
            tv.setColor(Color::Red);
            menuNum = 3;
        }
        if (IntRect(0, 0, 0, 0).contains(Mouse::getPosition(window))) {
            develop.setColor(Color::Red);
            menuNum = 4;
        }
        if (IntRect(0, 0, 0, 0).contains(Mouse::getPosition(window))) {
            exit.setColor(Color::Red);
            menuNum = 5;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 0;
                inter(window,
                      BackgroundInternetTexture,
                      ButtonExitTexture,
                      ButtonBackTexture);
            }
            if (menuNum == 2) {
                isMenu = 0;
                mob(window,
                    BackgroundMobileTexture,
                    ButtonExitTexture,
                    ButtonBackTexture);
            }
            if (menuNum == 3) {
                isMenu = 0;
                telev(window,
                      BackgroundTvTexture,
                      ButtonExitTexture,
                      ButtonBackTexture);
            }
            if (menuNum == 4) {
                isMenu = 0;
                dev(window,
                    BackgroundDevelopersTexture,
                    ButtonExitTexture,
                    ButtonBackTexture);
            }
            if (menuNum == 5)
                window.close();
        }
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(internet);
        window.draw(mobile);
        window.draw(tv);
        window.draw(develop);
        window.draw(exit);
        window.display();
    }
}
