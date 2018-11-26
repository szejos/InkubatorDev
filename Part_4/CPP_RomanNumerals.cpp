#include <assert.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

std::string makeRoman(int year)
{
    const static std::map<int, std::string> mapOfRom = { {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
                                            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
                                            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"} };

    std::string returnStr;

    while(year > 0)
    {
        for(auto it = mapOfRom.rbegin(); it != mapOfRom.rend(); ++it)
        {
            if( (year / it->first) > 0)
            {
                returnStr += it->second;
                year = year - it->first;
                break;
            }
        }
    }
    return returnStr;
}


void test_cases()
{


        assert(makeRoman(1000) == "M");

        assert(makeRoman(2008) == "MMVIII");

        assert(makeRoman(1666) == "MDCLXVI");

        assert(makeRoman(3422) == "MMMCDXXII");

        assert(makeRoman(1990) == "MCMXC");

        assert(makeRoman(9876) == "MMMMMMMMMDCCCLXXVI");

        assert(makeRoman(1) == "I");

        assert( makeRoman(0) == "");


}

int main()
{


        test_cases();


        return 0;
}


