#include <cstring>
#include <assert.h>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <string>


bool isPair(const std::string& direction, const std::string& directionSecond)
{
    static const std::map<std::string, std::string> dircetionsPairs = { { "NORTH", "SOUTH" }, { "SOUTH", "NORTH" }, { "EAST", "WEST" }, { "WEST", "EAST" } };
    if( dircetionsPairs.at(direction) == directionSecond )
    {
        return true;
    }
    return false;
}


std::vector<std::string> dirReduc(std::vector<std::string> &arr)
{
    std::vector<std::string> retVec = arr;
    bool flag = true;
    while ( flag )
    {
        flag = false;
        for(auto it = retVec.begin(); it != retVec.end() - 1; ++it)
        {
            if( retVec.size() < 2 )
                break;

            if( isPair(*it, *(it+1)) )
            {
                retVec.erase(it, it+2);
                flag = true;
            }
        }
    }


    return retVec;
}



void test_cases()
{
        std::vector<std::string> directions = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
        std::vector<std::string> result = dirReduc(directions);
        std::vector<std::string> solution = {"WEST"};
        assert( result == solution );


        std::vector<std::string> directions2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH","NORTH"};
        std::vector<std::string> result2 = dirReduc(directions2);
        std::vector<std::string> solution2 = {"NORTH"};
        assert( result2 == solution2 );

        std::vector<std::string> directions3 = {"NORTH","SOUTH"};
        std::vector<std::string> result3 = dirReduc(directions3);
        std::vector<std::string> solution3;
        assert( result3 == solution3 );



}

int main(int argc, char *argv[])
{

    test_cases();


    return 0;
}

