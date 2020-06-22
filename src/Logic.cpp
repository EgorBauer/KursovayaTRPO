#include "RadioBut.cpp"
#include <fstream>
#include <iostream>

class GiveRes {
private:
    int ans1, ans2;
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
}
