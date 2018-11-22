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



int calcComp(char* comp)
{
    int size = strlen(comp);
    int asci = 0;
    for(short i = 0; i < size; ++i)
    {
        asci += comp[i];
    }
    return asci;
}
bool switchFlag(int flag, int comp)
{
    bool ret = false;
    // If there were no diff between numbers, launch this case, otherwise launch lower cases
    if( flag  == 0 )
    {
        switch(comp)
        {
            case 121:
            case 122:
            case 123:
                ret = true;
            break;
            case 60:
            case 62:
            case 94:
                ret = false;
            break;
        }
    }
    else if( flag == 1 ) // if it was greater
    {
        switch(comp)
        {
            case 123:
            case 62:
            case 94:
                ret = true;
            break;
            case 122:
            case 60:
            case 121:
                ret = false;
            break;
        }

    }
    else // if it was smaller
    {
        switch(comp)
        {
            case 121:
            case 60:
            case 94:
                ret = true;
            break;
            case 122:
            case 123:
            case 62:
                ret = false;
            break;
        }

    }
    return ret;
}
bool equalComp(char* first, char* second, int comp, int fnL, int snL)
{
    // easy way for holding answer
    int flag = 0;
    for( int i = 0; i < fnL; ++i )
    {
        if( first[i] == second[i] )
        {
            continue;
        }
        else if ( first[i] > second[i] )
        {
            flag = 1;
        }
        else
        {
            flag = 2;
        }

        if( flag != 0 )
            break;
    }

    return switchFlag(flag, comp);

}
bool doCompare(char* first, char* second, char* comp, int fnLength, int snLength)
{
    int size = calcComp(comp);
    bool ret = false;
    if( fnLength < snLength )
    {
       if ( size == 94 || size == 60 )
       {
            ret = true;
       }
       else
       {
           ret = false;
       }
    }
    else if( fnLength > snLength )
    {
       if ( size == 62 || size == 94 )
       {
           ret = true;
       }
       else
       {
           ret = false;
       }
    }
    else if ( fnLength == snLength )
    {
        ret = equalComp(first, second, size, fnLength, snLength);
    }
    else
    {
        printf(" UNDEFINED BEH \n");
        ret = false;
    }

    return ret;
}
bool getNumbersAndCompare(char* word)
{
   unsigned int firstNumberLength = 0;
   unsigned int secondNumberLength = 0;
   char* firstNumber = NULL;
   char* secondNumber = NULL;
   char* comp = NULL;
   char* pChar;
   short indeks = 1;
   bool ret = false;

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
            comp = (char*)malloc((1 + strlen(pChar)) * sizeof(char));
            strcpy(comp, pChar);
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
   ret = doCompare(firstNumber, secondNumber, comp, firstNumberLength, secondNumberLength);
   free(firstNumber);
   free(secondNumber);
   free(comp);

   return ret;
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


