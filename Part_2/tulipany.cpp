#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

////////////////config//////////////

#define INTERFACE false

///////////////////////////////////

std::vector<int> stringToVector(int patchesNr, const std::string str)
{
    std::vector<int> myNumbers;
    std::stringstream iss( str );
    int number;
    while ( iss >> number && --patchesNr >= 0 )
    {
       if( std::isnan( number) )
       {
           std::cout << " Not a number, rolling out" << std::endl;
          // exit(1);
       }

       myNumbers.push_back( number );
    }
    if( patchesNr > 0 )
    {
        std::cout << " Not enough numbers" << std::endl;
        exit(0);
    }

    return myNumbers;
}

int getMissingTulips(std::vector<int> patches)
{
    int valTulips = 15000;

    std::sort( patches.begin(), patches.end() );
    patches.erase( unique( patches.begin(), patches.end() ),patches.end() );

    return ( valTulips - patches.size() );
}


void test_cases()
{

   assert( ( getMissingTulips( stringToVector(8, "3 6 2 2 4 6 3 7") ) == 14995 ) == true );

   assert( ( getMissingTulips( stringToVector(4, "10 11 10 15") ) == 14997 ) == true );

   assert( ( getMissingTulips( stringToVector(3, "44 33 221") ) == 14991 ) == false );

}

int main()
{

    if( !INTERFACE )
    {

        test_cases();
    }
    else
    {

        std::string line;
        int patchesNr, tempNr, tempPatches;

        std::cout << "Podaj liczbe grzadek: ";
        std::cin >> patchesNr;
        tempPatches = patchesNr;
        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Podaj odmiany tulipanow: ";
        std::getline(std::cin, line);

        std::vector<int> patches;

        std::istringstream stream(line);
        while (stream >> tempNr && --patchesNr >= 0 )
        {
            patches.push_back(tempNr);
        }

        std::cout << getMissingTulips( patches ) << std::endl;

    }


return 0;
}


