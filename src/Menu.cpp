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

    Sprite background(BackgroundTexture), internet(ButtonInternetTexture),
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

// Menu developers risuem
void dev(
        RenderWindow& window,
        Texture& BackgroundDevelopersTexture,
        Texture& ButtonExitTexture,
        Texture& ButtonBackTexture)
{
    Text text1;
    Font font;
    if (!font.loadFromFile("thirdparty/font/Shrift.ttf"))
        return;
    text1.setFont(font);
    text1.setPosition(150.f, 325.f); // *Otredachit koordinati
    text1.setString(
            "Nikita Moniev: Developer of program logic\n\nEgor Bauer: Graphic "
            "developer\n\nArtem Ivanov: Test coverage developer");
    Sprite background(BackgroundDevelopersTexture), Exit(ButtonExitTexture),
            Back(ButtonBackTexture);
    int menuNum = 0;
    background.setPosition(0, 0);
    Exit.setPosition(530, 800); // *Otredachit koordinati
    Back.setPosition(530, 800); // *Otredachit koordinati
    while (window.isOpen()) {
        Exit.setColor(Color::White);
        Back.setColor(Color::White);
        // *Otredachit koordinati
        if (IntRect(530, 800, 954, 86).contains(Mouse::getPosition(window))) {
            Exit.setColor(Color::Red);
            menuNum = 1;
        }
        // *Otredachit koordinati
        if (IntRect(530, 800, 954, 86).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 1;
                menu(window);
            }
        }
        // Posmotret kak vozrashat v iznachalnoe menu
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 2) {
                isMenu = 0;
                menu(window);
            }
        }
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        window.draw(text1);
        window.draw(Exit);
        window.draw(Back);
        window.display();
    }
}

