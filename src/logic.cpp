#include "RadioBut.cpp"
#include <fstream>
#include <iostream>

class GiveRes {
private:
    int ans1, ans2, ans4;
    std::string ans3;
    std::string name;
    std::vector<std::string> tariffs;
    std::string Shapka;

public:
    GiveRes()
    {
    }
    GiveRes(std::string str, int a, int b, std::string c)
    {
        nameSet(str);
        ans1Set(a);
        ans2Set(b);
        ans3Set(c);
    }

    GiveRes(std::string str, int a, int b, int c)
    {
        nameSet(str);
        ans1Set(a);
        ans2Set(b);
        ans3Set(std::to_string(c));
    }

    std::string Showtariffs()
    {
        std::string End = Shapka + "\n";
        if (tariffs.empty()) {
            return "Tariffs not found \n";
        }
        for (unsigned int i = 0; i < tariffs.size(); i++) {
            End += tariffs[i] + "\n";
        }
        return End;
    }

    void nameSet(std::string Value)
    {
        name = Value;
    }

    std::string nameGet()
    {
        return name;
    }

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
    void ans4Set(int Value)
    {
        ans4 = Value;
    }

    int ans4Get()
    {
        return ans4;
    }
    void ans3Set(std::string Value)
    {
        ans3 = Value;
    }

    std::string ans3Get()
    {
        return ans3;
    }

    void internet_get_ans(radio button, radio button1, radio button2)
    {
        Shapka = " NAME           COST(RUB)      SPEED          TV  \n";
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
                    if (button2.menuNumGet() == 3) {
                        tariffs.push_back(GiveRes::output_str());
                    } else {
                        if (otv == button2.menuNumGet()) {
                            tariffs.push_back(GiveRes::output_str());
                        } else
                            continue;
                    }
                } else
                    continue;
            } else
                continue;
        }

        answer1.close();
    }
    void mobile_get_ans(radio button, radio button1, radio button2)
    {
        Shapka = "NAME            COST(RUB)    INTERNET(GB)  PHONECALLS(min) "
                 "\n";
        std::fstream answer2("thirdparty/txt/mobile.txt", std::ios::in);
        for (int i = 0; i < 20; i++) {
            std::string temp;
            getline(answer2, temp);
            GiveRes::parcer(temp);
            int grr = 0;
            int grl = 0;
            int grr1 = 0;
            int grl1 = 0;
            int grr2 = 0;
            int grl2 = 0;

            if (button.menuNumGet() == 1) {
                grr = 0;
                grl = 500;
            }
            if (button.menuNumGet() == 2) {
                grr = 501;
                grl = 1000;
            }
            if (button.menuNumGet() == 3) {
                grr = 1001;
                grl = 2001;
            }
            if (button1.menuNumGet() == 1) {
                grr1 = 0;
                grl1 = 14;
            }
            if (button1.menuNumGet() == 2) {
                grr1 = 15;
                grl1 = 31;
            }
            if (button1.menuNumGet() == 3) {
                grr1 = 32;
                grl1 = 100000;
            }
            if (button2.menuNumGet() == 1) {
                grr2 = 0;
                grl2 = 500;
            }
            if (button2.menuNumGet() == 2) {
                grr2 = 501;
                grl2 = 1001;
            }
            if (button2.menuNumGet() == 3) {
                grr2 = 1001;
                grl2 = 10000;
            }
            if (grr < ans1 && grl > ans1) {
                if (grr1 < ans2 && grl1 > ans2) {
                    if (grr2 < ans4 && grl2 > ans4) {
                        tariffs.push_back(GiveRes::output_str());
                    } else
                        continue;
                } else
                    continue;
            } else
                continue;
        }

        answer2.close();
    }
    void tv_get_ans(radio button, radio button1, radio button2)
    {
        Shapka = " NAME           COST(RUB)     CHANNELS    HD CHANNELS \n";
        std::fstream answer3("thirdparty/txt/tv.txt", std::ios::in);
        for (int i = 0; i < 20; i++) {
            std::string temp;
            getline(answer3, temp);
            GiveRes::parcer(temp);
            int grr = 0;
            int grl = 0;
            int grr1 = 0;
            int grl1 = 0;
            int grr2 = 0;
            int grl2 = 0;

            if (button.menuNumGet() == 1) {
                grr = 0;
                grl = 600;
            }
            if (button.menuNumGet() == 2) {
                grr = 601;
                grl = 1000;
            }
            if (button.menuNumGet() == 3) {
                grr = 1001;
                grl = 6000;
            }
            if (button1.menuNumGet() == 1) {
                grr1 = 0;
                grl1 = 101;
            }
            if (button1.menuNumGet() == 2) {
                grr1 = 102;
                grl1 = 199;
            }
            if (button1.menuNumGet() == 3) {
                grr1 = 200;
                grl1 = 600;
            }
            if (button2.menuNumGet() == 1) {
                grr2 = 0;
                grl2 = 20;
            }
            if (button2.menuNumGet() == 2) {
                grr2 = 21;
                grl2 = 39;
            }
            if (button2.menuNumGet() == 3) {
                grr2 = 40;
                grl2 = 600;
            }
            if (grr < ans1 && grl > ans1) {
                if (grr1 < ans2 && grl1 > ans2) {
                    if (grr2 < ans4 && grl2 > ans4) {
                        tariffs.push_back(GiveRes::output_str());
                    } else
                        continue;
                } else
                    continue;
            } else
                continue;
        }

        answer3.close();
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

    std::string output_str()
    {
        long unsigned i;
        std::string temp;
        std::string time;
        temp.resize(50);
        temp = name;
        for (i = name.length(); i < 18; i++) {
            temp += " ";
        }

        time = std::to_string(ans1Get());

        temp += time;
        for (i += time.length(); i < 32; i++) {
            temp += " ";
        }

        time = std::to_string(ans2Get());

        temp += time;
        for (i += time.length(); i < 46; i++) {
            temp += " ";
        }
        time = ans3Get();
        temp += time;

        return temp;
    }
};
