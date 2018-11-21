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
void switchFlag(int flag, int comp, char* answer)
{
    // If there were no diff between numbers, launch this case, otherwise launch lower cases
    if( flag  == 0 )
    {
        switch(comp)
        {
            case 121:
            case 122:
            case 123:
                strncpy(answer, "TAK", 3);
            break;
            case 60:
            case 62:
            case 94:
                strncpy(answer, "NIE", 3);
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
                strncpy(answer, "TAK", 3);
            break;
            case 122:
            case 60:
            case 121:
                strncpy(answer, "NIE", 3);
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
                strncpy(answer, "TAK", 3);
            break;
            case 122:
            case 123:
            case 62:
                strncpy(answer, "NIE", 3);
            break;
        }

    }
}
void equalComp(char* first, char* second, int comp, int fnL, int snL, char* answer)
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

    switchFlag(flag, comp, answer);

}
char* doCompare(char* first, char* second, char* comp, int fnL, int snL)
{
    int size = calcComp(comp);
    char* answer = (char*)malloc(sizeof(char) * 4);
    if( fnL < snL )
    {
       if ( size == 94 || size == 60 )
       {

           strncpy(answer, "TAK", 3);
       }
       else
       {
           strncpy(answer, "NIE", 3);
       }
    }
    else if( fnL > snL )
    {
       if ( size == 62 || size == 94 )
       {
           strncpy(answer, "TAK", 3);
       }
       else
       {
           strncpy(answer, "NIE", 3);
       }
    }
    else if ( fnL == snL )
    {
        equalComp(first, second, size, fnL, snL, answer);
    }
    else
    {
        printf(" UNDEFINED BEH ");
        strncpy(answer, "NIE", 3);

    }

    printf("  %s %s %s   ---  %s   --- \n", first, comp, second, answer);
    return answer;


}
char* getNumbersAndCompare(char* word)
{

   unsigned int firstNumberLength = 0;
   unsigned int secondNumberLength = 0;
   char* firstNumber = NULL;
   char* secondNumber = NULL;
   char* comp = NULL;
   char* pChar;
   short indeks = 1;

   // extract numbers and comparator
   pChar = strtok (word, " ");
   while(pChar != NULL)
   {
       switch(indeks)
       {
        case 1:

            firstNumberLength = strlen(pChar);
            firstNumber = (char*)malloc(firstNumberLength * sizeof(char));
            strcpy(firstNumber, pChar);
              //printf("%d-%s\n ", (sizeof(pChar)/sizeof(char*)), pChar);
           // printf("%d-%s\n ", strlen(firstNumber), firstNumber);
        break;
        case 2:

           comp = (char*)malloc(strlen(pChar) * sizeof(char));
           strcpy(comp, pChar);
           //printf("%d-%s ", strlen(comp), comp);
        break;
        case 3:
          secondNumberLength = strlen(pChar);
          secondNumber = (char*)malloc(secondNumberLength * sizeof(char));
          strcpy(secondNumber, pChar);
          //printf("%d-%s ", strlen(secondNumber), secondNumber);
        break;
       }
       ++indeks;
       pChar = strtok(NULL, " ");

   }

   doCompare(firstNumber, secondNumber, comp, firstNumberLength, secondNumberLength);

   return comp;
}

void test_cases()
{
    char* words = (char*)malloc(sizeof(char) * 256);

    strcpy(words, "10113453453111 < 10113453453110");


    getNumbersAndCompare(words);



    free(words);

}

int main(int argc, char *argv[])
{

    test_cases();

    return 0;
}

