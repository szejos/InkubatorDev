#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>

std::string makeRoman(int year)
{
    std::map<int, std::string> mapOfRom = { {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
                                            {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
                                            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"} };

    std::string returnStr;

    while(year > 0)
    {
        for(auto it = mapOfRom.rbegin(); it != mapOfRom.rend(); ++it)
        {
            if( (year / it->first) )
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

        std::string test = makeRoman(1000);

        assert(test == "M");

        test = makeRoman(2008);
        assert(test == "MMVIII");

        test = makeRoman(1666);
        assert(test == "MDCLXVI");

        test = makeRoman(1990);
        assert(test == "MCMXC");

        test = makeRoman(1);
        assert(test == "I");

        test = makeRoman(0);
        assert(test == "");


}

int main()
{


        test_cases();





return 0;
}


