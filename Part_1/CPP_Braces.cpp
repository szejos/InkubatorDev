#include <cstring>
#include <assert.h>
#include <iostream>
#include <stack>
#include <map>


bool isPair(char& firstChar, char& secondChar)
{
    std::map<char, char> bracketPairs = { { '{', '}' }, { '[', ']' }, { '(', ')' } };
    if( bracketPairs[firstChar] == secondChar )
    {
        return true;
    }
    return false;
}
bool checkBracesOrder(const std::string& braces)
{
    const std::string openBraces = "[({";
    const  std::string closeBraces = "])}";

    std::stack<char> _stack;
    char c;

    //for(char& c : braces)
    for(auto it = braces.begin(); it != braces.end(); ++it)
    {
        c = *it;
        if ( openBraces.find(c) != std::string::npos )
        {
            _stack.push(c);
        }
        else
        {
            if( _stack.size() > 0 )
            {
                if ( isPair(_stack.top(), c)  )
                {
                     _stack.pop();
                }
                else
                {
                     return false;
                }
            }
            else
            {
                return false;
            }
        }

    }
    return true;

}

void test_cases()
{

        assert(checkBracesOrder("([{}])[]") == true);

        assert(checkBracesOrder("(]") == false);

        assert( checkBracesOrder("[(])") == false);

        assert(checkBracesOrder("[({})](]") == false);

        assert(checkBracesOrder("({[]}[]{})") == true);

        assert(checkBracesOrder("])") == false);

}

int main(int argc, char *argv[])
{

    test_cases();


    return 0;
}

