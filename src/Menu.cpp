#include "Menu.hpp"

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
    text1.setPosition(190.f, 220.f);
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
    Text text1, text2, text3, text4, text5, text6, text7, text8, text9, text10,
            text11, text12, text13;
    Font font;
    if (!font.loadFromFile("thirdparty/font/StyloBold.TTF"))
        return;
    text1.setFont(font);
    text1.setPosition(333.f, 65.f);
    text1.setString("Answer these questions");
    text2.setFont(font);
    text2.setPosition(40.f, 120.f);
    text2.setString("Desired price?(RUB)");
    text3.setFont(font);
    text3.setPosition(370.f, 120.f);
    text3.setString("Internet Speed?");
    text4.setFont(font);
    text4.setPosition(710.f, 100.f);
    text4.setString("The presence\nof television?");
    text5.setFont(font);
    text5.setPosition(105.f, 180.f);
    text5.setString("0-400");
    text6.setFont(font);
    text6.setPosition(105.f, 280.f);
    text6.setString("400-600");
    text7.setFont(font);
    text7.setPosition(105.f, 380.f);
    text7.setString("600-1000");
    text8.setFont(font);
    text8.setPosition(435.f, 180.f);
    text8.setString("0-50");
    text9.setFont(font);
    text9.setPosition(435.f, 280.f);
    text9.setString("50-100");
    text10.setFont(font);
    text10.setPosition(435.f, 380.f);
    text10.setString("100-500");
    text11.setFont(font);
    text11.setPosition(775.f, 180.f);
    text11.setString("Yes");
    text12.setFont(font);
    text12.setPosition(775.f, 280.f);
    text12.setString("No");
    text13.setFont(font);
    text13.setPosition(775.f, 380.f);
    text13.setString("Dont care");

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
                GiveRes cnt;
                cnt.internet_get_ans(button, button1, button2);
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture,
                       cnt);
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
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.draw(text7);
        window.draw(text8);
        window.draw(text9);
        window.draw(text10);
        window.draw(text11);
        window.draw(text12);
        window.draw(text13);
        window.draw(Back);
        window.draw(Count);
        button.draw(40, 180, 280, 380, window, false);
        button1.draw(370, 180, 280, 380, window, false);
        button2.draw(710, 180, 280, 380, window, false);
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
    Text text1, text2, text3, text4, text5, text6, text7, text8, text9, text10,
            text11, text12, text13;
    Font font;
    if (!font.loadFromFile("thirdparty/font/StyloBold.TTF"))
        return;
    text1.setFont(font);
    text1.setPosition(333.f, 65.f);
    text1.setString("Answer these questions");
    text2.setFont(font);
    text2.setPosition(40.f, 120.f);
    text2.setString("Desired price?(RUB)");
    text3.setFont(font);
    text3.setPosition(370.f, 120.f);
    text3.setString("Amount of gigabytes?");
    text4.setFont(font);
    text4.setPosition(710.f, 120.f);
    text4.setString("Amount of minutes?");
    text5.setFont(font);
    text5.setPosition(105.f, 180.f);
    text5.setString("0-500");
    text6.setFont(font);
    text6.setPosition(105.f, 280.f);
    text6.setString("500-1000");
    text7.setFont(font);
    text7.setPosition(105.f, 380.f);
    text7.setString("1000-2000");
    text8.setFont(font);
    text8.setPosition(435.f, 180.f);
    text8.setString("0-14");
    text9.setFont(font);
    text9.setPosition(435.f, 280.f);
    text9.setString("15-31");
    text10.setFont(font);
    text10.setPosition(435.f, 380.f);
    text10.setString("Unlimited");
    text11.setFont(font);
    text11.setPosition(775.f, 180.f);
    text11.setString("0-500");
    text12.setFont(font);
    text12.setPosition(775.f, 280.f);
    text12.setString("500-1000");
    text13.setFont(font);
    text13.setPosition(775.f, 380.f);
    text13.setString("Unlimited");
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
                GiveRes cnt;
                cnt.mobile_get_ans(button, button1, button2);
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture,
                       cnt);
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
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.draw(text7);
        window.draw(text8);
        window.draw(text9);
        window.draw(text10);
        window.draw(text11);
        window.draw(text12);
        window.draw(text13);
        window.draw(Back);
        window.draw(Count);
        button.draw(40, 180, 280, 380, window, false);
        button1.draw(370, 180, 280, 380, window, false);
        button2.draw(710, 180, 280, 380, window, false);
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
    Text text1, text2, text3, text4, text5, text6, text7, text8, text9, text10,
            text11, text12, text13;
    Font font;
    if (!font.loadFromFile("thirdparty/font/StyloBold.TTF"))
        return;
    text1.setFont(font);
    text1.setPosition(333.f, 65.f);
    text1.setString("Answer these questions");
    text2.setFont(font);
    text2.setPosition(40.f, 120.f);
    text2.setString("Desired price?(RUB)");
    text3.setFont(font);
    text3.setPosition(370.f, 120.f);
    text3.setString("Amount of channels?");
    text4.setFont(font);
    text4.setPosition(710.f, 120.f);
    text4.setString("Amount of HD?");
    text5.setFont(font);
    text5.setPosition(105.f, 180.f);
    text5.setString("0-600");
    text6.setFont(font);
    text6.setPosition(105.f, 280.f);
    text6.setString("600-1000");
    text7.setFont(font);
    text7.setPosition(105.f, 380.f);
    text7.setString("1000-3000");
    text8.setFont(font);
    text8.setPosition(435.f, 180.f);
    text8.setString("0-100");
    text9.setFont(font);
    text9.setPosition(435.f, 280.f);
    text9.setString("100-200");
    text10.setFont(font);
    text10.setPosition(435.f, 380.f);
    text10.setString("200-300");
    text11.setFont(font);
    text11.setPosition(775.f, 180.f);
    text11.setString("0-20");
    text12.setFont(font);
    text12.setPosition(775.f, 280.f);
    text12.setString("20-40");
    text13.setFont(font);
    text13.setPosition(775.f, 380.f);
    text13.setString("40-100");
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
                GiveRes cnt;
                cnt.tv_get_ans(button, button1, button2);
                result(window,
                       BackgroundTexture,
                       ButtonExitTexture,
                       ButtonBackTexture,
                       cnt);
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
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.draw(text7);
        window.draw(text8);
        window.draw(text9);
        window.draw(text10);
        window.draw(text11);
        window.draw(text12);
        window.draw(text13);
        window.draw(Back);
        window.draw(Count);
        button.draw(40, 180, 280, 380, window, false);
        button1.draw(370, 180, 280, 380, window, false);
        button2.draw(710, 180, 280, 380, window, false);
        window.display();
    }
}

// Posledneya menu
void result(
        RenderWindow& window,
        Texture& BackgroundTexture,
        Texture& ButtonExitTexture,
        Texture& ButtonBackTexture,
        GiveRes cnt)
{
    Sprite background(BackgroundTexture), Exit(ButtonExitTexture),
            Back(ButtonBackTexture);
    int menuNum = 0;
    Text Res;
    Font font;
    if (!font.loadFromFile("thirdparty/font/StyloBold.TTF"))
        return;
    Res.setFont(font);
    Res.setPosition(20.f, 90.f);
    Res.setString(cnt.Showtariffs());
    Res.setLetterSpacing(1);
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
        window.draw(Res);
        window.draw(Exit);
        window.draw(Back);
        window.display();
    }
}
