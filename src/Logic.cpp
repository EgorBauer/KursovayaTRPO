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
