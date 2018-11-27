#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////
// ==  - equals 122 in ASCI
// !=  - eq 94
// <   - eq 60
// >   - eq 62
// <=  - eq 121
// >=  - eq 123
enum eCompSign {EQ = 122, NOTQ = 94, LESS = 60, GRT = 62, LESSEQ = 121, GRTEQ = 123};


short calcComp(const char* comp)
{
    const short size = strlen(comp);
    short asci = 0;
    for(short i = 0; i < size; ++i)
    {
        asci += comp[i];
    }
    return asci;
}
bool switchFlag(const enum eCompSign flag, const short compareSign)
{
    bool retFlag = false;
    // switch according to value of compareSign

    switch(compareSign)
    {
        case LESSEQ:
            retFlag = ( flag == EQ || flag == LESS ) ? true : false;
        break;
        case EQ:
            retFlag = ( flag == EQ ) ? true : false;
        break;
        case GRTEQ:
            retFlag = ( flag == EQ || flag == GRT) ? true : false;
        break;
        case LESS:
            retFlag = ( flag == LESS ) ? true : false;
        break;
        case GRT:
            retFlag = ( flag == GRT ) ? true : false;
        break;
        case NOTQ:
            retFlag = ( flag != EQ ) ? true : false;
        break;
    }


    return retFlag;
}
bool equalComp(char* firstNumber, char* secondNumber, const short compareSign, const unsigned int firstNumberLength, const unsigned int secondNumberLength)
{
    // easy way for holding answer
    enum eCompSign flag = EQ;
    for( int i = 0; i < firstNumberLength; ++i )
    {
        if( firstNumber[i] == secondNumber[i] )
        {
            continue;
        }
        else if ( firstNumber[i] > secondNumber[i] )
        {
            flag = GRT;
        }
        else
        {
            flag = LESS;
        }

        if( flag != 0 )
            break;
    }
    return switchFlag(flag, compareSign);

}
bool doCompare(char* firstNumber, char* secondNumber, char* compareSign, const unsigned int firstNumberLength, const unsigned int secondNumberLength)
{
    const short size = calcComp(compareSign);
    bool retFlag = false;
    if( firstNumberLength < secondNumberLength )
    {
        retFlag = (size == NOTQ || size == LESS) ? true : false;

    }
    else if( firstNumberLength > secondNumberLength )
    {
        retFlag = (size == GRT || size == NOTQ) ? true : false;

    }
    else if ( firstNumberLength == secondNumberLength )
    {
        retFlag = equalComp(firstNumber, secondNumber, size, firstNumberLength, secondNumberLength);
    }
    else
    {
        printf(" UNDEFINED BEH \n");
        retFlag = false;
    }

    return retFlag;
}
bool getNumbersAndCompare(char* word)
{
   unsigned int firstNumberLength = 0;
   unsigned int secondNumberLength = 0;
   char* firstNumber = NULL;
   char* secondNumber = NULL;
   char* compareSign = NULL;
   char* pChar;
   short indeks = 1;
   bool retFlag = false;

   // extract numbers and comparator
   pChar = strtok (word, " ");
   while(pChar != NULL)
   {
       switch(indeks)
       {
        case 1:
            firstNumberLength = strlen(pChar);
            firstNumber = (char*)malloc((1 + firstNumberLength) * sizeof(char));
            strcpy(firstNumber, pChar);
        break;
        case 2:
            compareSign = (char*)malloc((1 + strlen(pChar)) * sizeof(char));
            strcpy(compareSign, pChar);
        break;
        case 3:
            secondNumberLength = strlen(pChar);
            secondNumber = (char*)malloc((1 + secondNumberLength) * sizeof(char));
            strcpy(secondNumber, pChar);
        break;
       }
       ++indeks;
       pChar = strtok(NULL, " ");
   }
   retFlag = doCompare(firstNumber, secondNumber, compareSign, firstNumberLength, secondNumberLength);
   free(firstNumber);
   free(secondNumber);
   free(compareSign);

   return retFlag;
}

void test_cases()
{
    const int MAX_LENGTH = 1024;
    char* words = (char*)malloc(sizeof(char) * MAX_LENGTH);
    strcpy(words, "1 < 2");

    bool ans = getNumbersAndCompare(words);
    assert ( ans ==  true );

    strcpy(words, "11111 > 11111");
    ans = getNumbersAndCompare(words);
    assert ( ans == false );


    strcpy(words, "2222 != 312");
    ans = getNumbersAndCompare(words);
    assert ( ans == true );


    strcpy(words, "9998278273723 < 21893712893711111");
    ans = getNumbersAndCompare(words);
    assert ( ans == true );


    strcpy(words, "12121234142342342455654634 == 12121234142342342455654634");
    ans = getNumbersAndCompare(words);
    assert ( ans == true );


    strcpy(words, "12121234142342342455654634 != 12121234142342342455654634");
    ans = getNumbersAndCompare(words);
    assert ( ans == false );


    //  answer = (ret) ? strncpy(answer, "TAK", 3) : strncpy(answer, "NIE", 3);
    free(words);
}

int main(int argc, char *argv[])
{
    test_cases();
    return 0;
}


