#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <sstream>

////////////////config//////////////

#define INTERFACE false
#define DICESIDES 6

///////////////////////////////////

std::string makeHist(int diceRolls, const std::vector<int>& rollsResult)
{
    std::string hist;
    std::string temp;
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
            if( rollsResult.at(i) > 9 )
                flag = true;

            if( dice ==  rollsResult.at(i)  && dice != 0 )
            {

                hist.append( std::to_string(dice) );
               // if( flag )
             //       hist.append(" ");

            }
            else if( dice < rollsResult.at(i) )
            {
                //if( flag )
                  //  hist.append("# ");
              //  else
                    hist.append("#");
            }
            else
            {
                //if( flag )
                //    hist.append("  ");
             //   else

                    hist.append(" ");
            }

            if( i < DICESIDES - 1 )
            {
               // if( flag )
                //    hist.append("  ");
               // else
                    hist.append(" ");
            }

        }
        flag = false;
        hist.append("\n");
    }

    for(int i = 0; i < DICESIDES * 2 - 1; ++i )
    {
          hist.append("-");
    }
    hist.append("\n");
    for(int i = 1; i < DICESIDES + 1; ++i )
    {
          hist.append( std::to_string( i ) );
          if( i < DICESIDES )
          {
               hist.append(" ");
          }
          else
          {
              hist.append("\n");
          }
    }
    return hist;

}


void test_cases()
{
    int diceRolls = 26;
    std::vector<int> rollsResult = {7, 3, 10, 1, 0, 5};
    //int diceRolls = 100;
   // std::vector<int> rollsResult = {10, 10, 20, 20, 20, 20};
    std::string val = makeHist(diceRolls, rollsResult);

    std::cout<<val<<std::endl;

}

void interface()
{
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


