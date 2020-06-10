#include "Menu.hpp"
#include "RadioBut.hpp"

int isMenu = 0;

void menu(RenderWindow& window) // risuem Glavnoe Menu
{
    Texture BackgroundTexture, ButtonInternetTexture, ButtonMobileTexture,
            ButtonTvTexture, ButtonDevelopersTexture, ButtonExitTexture,
            ButtonBackTexture, ButtonCountTexture, BackgroundInternetTexture,
            BackgroundMobileTexture, BackgroundTvTexture,
            BackgroundDevelopersTexture;

    BackgroundTexture.loadFromFile("image/Fon.jpg");
    BackgroundInternetTexture.loadFromFile("image/FonInternet.jpg");
    BackgroundMobileTexture.loadFromFile("image/FonMobile.jpg");
    BackgroundTvTexture.loadFromFile("image/FonTV.jpg");
    BackgroundDevelopersTexture.loadFromFile("image/FonDevelopers.jpg");
    ButtonInternetTexture.loadFromFile("image/Internetknopka.png");
    ButtonMobileTexture.loadFromFile("image/Mobileknopka.png");
    ButtonTvTexture.loadFromFile("image/TVknopka.png");
    ButtonDevelopersTexture.loadFromFile("image/Developersknopka.png");
    ButtonExitTexture.loadFromFile("image/Exitknopka.png");
    ButtonBackTexture.loadFromFile("image/Backknopka.png");
    ButtonCountTexture.loadFromFile("image/Countknopka.png");

    Sprite background(BackgroundTexture), internet(ButtonInternetTexture),
            mobile(ButtonMobileTexture), tv(ButtonTvTexture),
            develop(ButtonDevelopersTexture), exit(ButtonExitTexture);

    int menuNum = 0;
    background.setPosition(0, 0);
    internet.setPosition(90, 200);
    mobile.setPosition(90, 300);
    tv.setPosition(90, 400);
    develop.setPosition(810, 440);
    exit.setPosition(810, 500);

    while (window.isOpen()) {
        internet.setColor(Color::White);
        mobile.setColor(Color::White);
        tv.setColor(Color::White);
        develop.setColor(Color::White);
        exit.setColor(Color::White);

        menuNum = 0;
        if (IntRect(90, 200, 220, 48).contains(Mouse::getPosition(window))) {
            internet.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(90, 300, 220, 48).contains(Mouse::getPosition(window))) {
            mobile.setColor(Color::Red);
            menuNum = 2;
        }
        if (IntRect(90, 400, 220, 48).contains(Mouse::getPosition(window))) {
            tv.setColor(Color::Red);
            menuNum = 3;
        }
        if (IntRect(810, 440, 153, 48).contains(Mouse::getPosition(window))) {
            develop.setColor(Color::Red);
            menuNum = 4;
        }
        if (IntRect(810, 500, 153, 48).contains(Mouse::getPosition(window))) {
            exit.setColor(Color::Red);
            menuNum = 5;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 2;
                inter(window,
                      BackgroundInternetTexture,
                      ButtonBackTexture,
                      ButtonCountTexture,
                      BackgroundTexture,
                      ButtonExitTexture);
            }
            if (menuNum == 2) {
                isMenu = 3;
                mob(window,
                    BackgroundMobileTexture,
                    ButtonBackTexture,
                    ButtonCountTexture,
                    BackgroundTexture,
                    ButtonExitTexture);
            }
            if (menuNum == 3) {
                isMenu = 4;
                telev(window,
                      BackgroundTvTexture,
                      ButtonBackTexture,
                      ButtonCountTexture,
                      BackgroundTexture,
                      ButtonExitTexture);
            }
            if (menuNum == 4) {
                isMenu = 1;
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
    if (!font.loadFromFile("thirdparty/font/StyloBold.TTF"))
        return;
    text1.setFont(font);
    text1.setPosition(240.f, 240.f); // *Otredachit koordinati i dobavit text
    text1.setString(
            "Nikita Moniev: Developer of program logic\n\nEgor Bauer: Graphic "
            "developer\n\nArtem Ivanov: Test coverage developer");
    Sprite background(BackgroundDevelopersTexture), Exit(ButtonExitTexture),
            Back(ButtonBackTexture);
    int menuNum = 0;
    background.setPosition(0, 0);
    Exit.setPosition(810, 500);
    Back.setPosition(40, 500);
    while (window.isOpen()) {
        Exit.setColor(Color::White);
        Back.setColor(Color::White);
        menuNum = 0;
        if (IntRect(810, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Exit.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(40, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                window.close();
            }
        }
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

void inter(
        RenderWindow& window,
        Texture& BackgroundInternetTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture)
{
    Sprite background(BackgroundInternetTexture), Back(ButtonBackTexture),
            Count(ButtonCountTexture);
    radio button;
    radio button1;
    radio button2;
    int menuNum = 0;
    background.setPosition(0, 0);
    Back.setPosition(40, 500);
    Count.setPosition(810, 500);
    while (window.isOpen()) {
        Back.setColor(Color::White);
        Count.setColor(Color::White);
        menuNum = 0;
        if (IntRect(810, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Count.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(40, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 5;
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture);
            }
        }
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
        window.draw(Back);
        window.draw(Count);
        // *izmenit koordinati i dobavit text dlya knopok
        button.draw(50, 40, 80, 120, window);
        button1.draw(120, 40, 80, 120, window);
        button2.draw(190, 40, 80, 120, window);
        window.display();
    }
}

void mob(
        RenderWindow& window,
        Texture& BackgroundMobileTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture)
{
    Sprite background(BackgroundMobileTexture), Back(ButtonBackTexture),
            Count(ButtonCountTexture);
    radio button;
    radio button1;
    radio button2;
    int menuNum = 0;
    background.setPosition(0, 0);
    Back.setPosition(40, 500);
    Count.setPosition(810, 500);
    while (window.isOpen()) {
        Back.setColor(Color::White);
        Count.setColor(Color::White);
        menuNum = 0;
        if (IntRect(810, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Count.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(40, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 5;
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture);
            }
        }
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
        window.draw(Back);
        window.draw(Count);
        // *izmenit koordinati i dobavit text dlya knopok
        button.draw(50, 40, 80, 120, window);
        button1.draw(120, 40, 80, 120, window);
        button2.draw(190, 40, 80, 120, window);
        window.display();
    }
}

void telev(
        RenderWindow& window,
        Texture& BackgroundTvTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture)
{
    Sprite background(BackgroundTvTexture), Back(ButtonBackTexture),
            Count(ButtonCountTexture);
    radio button;
    radio button1;
    radio button2;
    int menuNum = 0;
    background.setPosition(0, 0);
    Back.setPosition(40, 500);
    Count.setPosition(810, 500);
    while (window.isOpen()) {
        Back.setColor(Color::White);
        Count.setColor(Color::White);
        menuNum = 0;
        if (IntRect(810, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Count.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(40, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 5;
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture);
            }
        }
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
        window.draw(Back);
        window.draw(Count);
        // *izmenit koordinati i dobavit text dlya knopok
        button.draw(50, 40, 80, 120, window);
        button1.draw(120, 40, 80, 120, window);
        button2.draw(190, 40, 80, 120, window);
        window.display();
    }
}

// Posledneya menu dobavti vivod podhodyashevo tarifa v vide teksta
void result(
        RenderWindow& window,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture,
        Texture& ButtonBackTexture)
{
    Sprite background(BackgroundTexture), Exit(ButtonExitTexture),
            Back(ButtonBackTexture);
    int menuNum = 0;
    background.setPosition(0, 0);
    Exit.setPosition(420, 500);
    Back.setPosition(40, 500);
    while (window.isOpen()) {
        Exit.setColor(Color::White);
        Back.setColor(Color::White);
        menuNum = 0;
        if (IntRect(420, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Exit.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(40, 500, 153, 48).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                window.close();
            }
        }
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
        window.draw(Exit);
        window.draw(Back);
        window.display();
    }
}
