#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <sstream>


std::string makeHist(int diceRolls, const std::vector<int>& rollsResult)
{
    std::string hist;
    std::string temp;
    const int DICESIDES = 6;
    bool flag = false;
    int maxRes = *std::max_element(rollsResult.begin(), rollsResult.end() );

    if ( diceRolls != std::accumulate(rollsResult.begin(),rollsResult.end(), 0) )
    {
        std::cout << "Value of rolls do not match witch the sum of rolls, rolling out!" << std::endl;
        exit(0);
    }

    for(int dice = maxRes; dice >= 0; --dice)
    {
        for(int i = 0; i < DICESIDES; ++i )
        {
            if( dice ==  rollsResult.at(i)  && dice != 0 )
            {
                  temp.append( std::to_string(dice) );
                  flag = ( rollsResult.at(i) > 9 ) ? true : false;
            }
            else if( dice < rollsResult.at(i) )
            {
                 temp.append("#");
            }
            else
            {
                 temp.append(" ");
            }

            if( !flag )
            {
                 temp.append(" ");
            }
            else
            {
                flag = false;
            }
        }

        // triming trailing spaces
        temp.erase(std::find_if(temp.rbegin(), temp.rend(), std::bind1st(std::not_equal_to<char>(), ' ')).base(), temp.end());
        hist += temp;
        temp.clear();
        flag = false;
        hist.append("\n");
    }

    hist.append("-----------\n1 2 3 4 5 6\n");

    return hist;
}


void test_cases()
{

    std::vector<int> rollsResult = {7, 3, 10, 1, 0, 5};

    std::string testString =    "    10\n"
                                "    #\n"
                                "    #\n"
                                "7   #\n"
                                "#   #\n"
                                "#   #     5\n"
                                "#   #     #\n"
                                "# 3 #     #\n"
                                "# # #     #\n"
                                "# # # 1   #\n"
                                "# # # #   #\n"
                                "-----------\n"
                                "1 2 3 4 5 6\n";

       std::string getHist = makeHist(26, rollsResult);
       assert(getHist.compare(testString) == 0);


       testString.clear();
       getHist.clear();
       rollsResult.clear();
       rollsResult = {5, 4, 9, 1, 0, 4};
       testString = "    9\n"
                    "    #\n"
                    "    #\n"
                    "    #\n"
                    "5   #\n"
                    "# 4 #     4\n"
                    "# # #     #\n"
                    "# # #     #\n"
                    "# # # 1   #\n"
                    "# # # #   #\n"
                    "-----------\n"
                    "1 2 3 4 5 6\n";
       getHist = makeHist(23, rollsResult);
       assert(getHist.compare(testString) == 0);

}

void interface()
{
    const int DICESIDES = 6;
    int diceRolls;
    std::vector<int> rollsResult;
    std::string line;
    int tempDiceRolls, tempNr;

    std::cout << "Podaj liczbe rzutow: ";
    std::cin >> diceRolls;
    tempDiceRolls = DICESIDES;
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Podaj wyniki dla kolejnych scian kostki: ";
    std::getline(std::cin, line);


    std::istringstream stream(line);
    while (stream >> tempNr && --tempDiceRolls >= 0 )
    {
        rollsResult.push_back(tempNr);
    }


    std::string val = makeHist(diceRolls, rollsResult);

    std::cout<<val<<std::endl;

}
int main()
{
    const bool INTERFACE = false;

    if( !INTERFACE )
    {

        test_cases();
    }
    else
    {
        interface();
    }


return 0;
}


