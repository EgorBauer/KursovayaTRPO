#include "RadioBut.cpp"
#include <fstream>
#include <iostream>

class GiveRes {
private:
    int ans1, ans2, ans4;
    std::string ans3;

public:
    void ans1Set(int Value)
    {
        ans1 = Value;
    }

    int ans1Get()
    {
        return ans1;
    }
    void ans2Set(int Value)
    {
        ans2 = Value;
    }

    int ans2Get()
    {
        return ans2;
    }
    void ans3Set(std::string Value)
    {
        ans3 = Value;
    }

    std::string ans3Get()
    {
        return ans3;
    }
    void ans4Set(int Value)
    {
        ans4 = Value;
    }

    int ans4Get()
    {
        return ans4;
    }

    void internet_get_ans(radio button, radio button1, radio button2)
    {
        std::fstream answer1("thirdparty/txt/inet.txt", std::ios::in);
        for (int i = 0; i < 20; i++) {
            std::string temp;
            getline(answer1, temp);
            GiveRes::parcer(temp);
            int grr = 0;
            int grl = 0;
            int grr1 = 0;
            int grl1 = 0;
            int otv;

            if (button.menuNumGet() == 1) {
                grr = 0;
                grl = 401;
            }
            if (button.menuNumGet() == 2) {
                grr = 401;
                grl = 601;
            }
            if (button.menuNumGet() == 3) {
                grr = 601;
                grl = 2000;
            }
            if (button1.menuNumGet() == 1) {
                grr1 = 0;
                grl1 = 51;
            }
            if (button1.menuNumGet() == 2) {
                grr1 = 51;
                grl1 = 101;
            }
            if (button1.menuNumGet() == 3) {
                grr1 = 102;
                grl1 = 1000;
            }
            if (ans3 == "YES") {
                otv = 1;
            }
            if (ans3 == "NO") {
                otv = 2;
            }
            if (ans3 == "IDC") {
                otv = 3;
            }

            if (grr < ans1 && grl > ans1) {
                if (grr1 < ans2 && grl1 > ans2) {
                    if (otv == button2.menuNumGet()) {
                        tariffs.push_back(temp);
                    } else
                        continue;
                } else
                    continue;
            } else
                continue;
        }
    }

    answer1.close();
}
}
void mobile_get_ans(radio button, radio button1, radio button2)
{
}
void tv_get_ans(radio button, radio button1, radio button2)
{
}
void parcer(std::string value)
{
    long unsigned i = 0;
    std::string time;
    char* pEnd;
    name = "";
    while (value[i] != ' ') {
        name += value[i];
        i++;
    }
    while (value[i] == ' ') {
        i++;
    }
    while (value[i] != ' ') {
        time += value[i];
        i++;
    }
    ans1Set(strtol(time.c_str(), &pEnd, 10));
    time = "";
    while (value[i] == ' ') {
        i++;
    }
    while (value[i] != ' ') {
        time += value[i];
        i++;
    }
    ans2 = strtol(time.c_str(), &pEnd, 10);
    time = "";
    while (value[i] == ' ') {
        i++;
    }
    while (value[i] != ' ' && value[i] != '\0') {
        time += value[i];
        i++;
    }
    ans3 = time;
    ans4 = strtol(time.c_str(), &pEnd, 10);
}
}
