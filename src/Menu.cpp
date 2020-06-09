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
    // *Nujno budet dobavit image
    BackgroundTexture.loadFromFile("image/Fon.jpg");
    BackgroundInternetTexture.loadFromFile("image/Fon.jpg");
    BackgroundMobileTexture.loadFromFile("");
    BackgroundTvTexture.loadFromFile("");
    BackgroundDevelopersTexture.loadFromFile("image/Fon.jpg");
    ButtonInternetTexture.loadFromFile("image/Knopka.jpg");
    ButtonMobileTexture.loadFromFile("image/Knopka.jpg");
    ButtonTvTexture.loadFromFile("image/Knopka.jpg");
    ButtonDevelopersTexture.loadFromFile("image/Knopka.jpg");
    ButtonExitTexture.loadFromFile("image/Knopka.jpg");
    ButtonBackTexture.loadFromFile("image/Knopka.jpg");
    ButtonCountTexture.loadFromFile("image/Knopka.jpg");

    Sprite background(BackgroundTexture), internet(ButtonInternetTexture),
            mobile(ButtonMobileTexture), tv(ButtonTvTexture),
            develop(ButtonDevelopersTexture), exit(ButtonExitTexture);

    int menuNum = 0; // *Nujno podstavit koordinati knopok
    background.setPosition(0, 0);
    internet.setPosition(100, 200);
    mobile.setPosition(100, 300);
    tv.setPosition(100, 400);
    develop.setPosition(630, 400);
    exit.setPosition(630, 500);

    while (window.isOpen()) {
        internet.setColor(Color::White);
        mobile.setColor(Color::White);
        tv.setColor(Color::White);
        develop.setColor(Color::White);
        exit.setColor(Color::White);

        menuNum = 0; // *Nujno podstavit koordinati knopok dly vseh if
        if (IntRect(100, 200, 470, 90).contains(Mouse::getPosition(window))) {
            internet.setColor(Color::Red);
            menuNum = 1;
        }
        if (IntRect(100, 300, 470, 90).contains(Mouse::getPosition(window))) {
            mobile.setColor(Color::Red);
            menuNum = 2;
        }
        if (IntRect(100, 400, 470, 90).contains(Mouse::getPosition(window))) {
            tv.setColor(Color::Red);
            menuNum = 3;
        }
        if (IntRect(630, 400, 470, 90).contains(Mouse::getPosition(window))) {
            develop.setColor(Color::Red);
            menuNum = 4;
        }
        if (IntRect(630, 500, 470, 90).contains(Mouse::getPosition(window))) {
            exit.setColor(Color::Red);
            menuNum = 5;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 2;
                inter(window,
                      BackgroundInternetTexture,
                      ButtonBackTexture,
                      ButtonCountTexture);
            }
            if (menuNum == 2) {
                isMenu = 3;
                mob(window,
                    BackgroundMobileTexture,
                    ButtonBackTexture,
                    ButtonCountTexture);
            }
            if (menuNum == 3) {
                isMenu = 4;
                telev(window,
                      BackgroundTvTexture,
                      ButtonBackTexture,
                      ButtonCountTexture);
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
    Exit.setPosition(630, 500); // *Otredachit koordinati
    Back.setPosition(30, 500);  // *Otredachit koordinati
    while (window.isOpen()) {
        Exit.setColor(Color::White);
        Back.setColor(Color::White);
        // *Otredachit koordinati
        menuNum = 0;
        if (IntRect(630, 500, 470, 90).contains(Mouse::getPosition(window))) {
            Exit.setColor(Color::Red);
            menuNum = 1;
        }
        // *Otredachit koordinati
        if (IntRect(30, 500, 470, 90).contains(Mouse::getPosition(window))) {
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

// Posledneya menu
// void result(

void inter(
        RenderWindow& window,
        Texture& BackgroundInternetTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture)
{
    Sprite background(BackgroundInternetTexture), Back(ButtonBackTexture),
            Count(ButtonCountTexture);
    radio button;  
    radio button1;      
    int menuNum = 0;
    background.setPosition(0, 0);
    Back.setPosition(30, 500);   // *Otredachit koordinati
    Count.setPosition(630, 500); // *Otredachit koordinati
    while (window.isOpen()) {
        Back.setColor(Color::White);
        Count.setColor(Color::White);
        // *Otredachit koordinati
        menuNum = 0;
        if (IntRect(630, 500, 470, 90).contains(Mouse::getPosition(window))) {
            Count.setColor(Color::Red);
            menuNum = 1;
        }
        // *Otredachit koordinati
        if (IntRect(30, 500, 470, 90).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        /*if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 5;
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture);
            }
        } */
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
        button.draw(50, 40, 80, 120, window);
        button1.draw(100, 40, 80, 120, window);
        window.display();
    }
}

void mob(
        RenderWindow& window,
        Texture& BackgroundMobileTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture)
{
    Sprite background(BackgroundMobileTexture), Back(ButtonBackTexture),
            Count(ButtonCountTexture);
    int menuNum = 0;
    background.setPosition(0, 0);
    Back.setPosition(30, 500);   // *Otredachit koordinati
    Count.setPosition(630, 500); // *Otredachit koordinati
    while (window.isOpen()) {
        Back.setColor(Color::White);
        Count.setColor(Color::White);
        // *Otredachit koordinati
        menuNum = 0;
        if (IntRect(630, 500, 470, 90).contains(Mouse::getPosition(window))) {
            Count.setColor(Color::Red);
            menuNum = 1;
        }
        // *Otredachit koordinati
        if (IntRect(30, 500, 470, 90).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        /*if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 5;
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture);
            }
        } */
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
        window.display();
    }
}

void telev(
        RenderWindow& window,
        Texture& BackgroundTvTexture,
        Texture& ButtonBackTexture,
        Texture& ButtonCountTexture)
{
    Sprite background(BackgroundTvTexture), Back(ButtonBackTexture),
            Count(ButtonCountTexture);
    int menuNum = 0;
    background.setPosition(0, 0);
    Back.setPosition(30, 500);   // *Otredachit koordinati
    Count.setPosition(630, 500); // *Otredachit koordinati
    while (window.isOpen()) {
        Back.setColor(Color::White);
        Count.setColor(Color::White);
        // *Otredachit koordinati
        menuNum = 0;
        if (IntRect(630, 500, 470, 90).contains(Mouse::getPosition(window))) {
            Count.setColor(Color::Red);
            menuNum = 1;
        }
        // *Otredachit koordinati
        if (IntRect(30, 500, 470, 90).contains(Mouse::getPosition(window))) {
            Back.setColor(Color::Red);
            menuNum = 2;
        }

        /*if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                isMenu = 5;
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture);
            }
        } */
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
        window.display();
    }
}
