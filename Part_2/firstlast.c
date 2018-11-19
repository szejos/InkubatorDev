#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef int t_int;
#define maxActVal 10
#define INTERFACE 0


void randPrices(t_int* daysTable, t_int numberOfDays)
{
    for( t_int i = 0; i < numberOfDays; ++i)
    {
        daysTable[i] = (1 + rand() % (( maxActVal + 1 ) - 1));
    }

}
t_int* getDays(t_int numberOfDays, t_int actionPrice, t_int* daysTable)
{
    t_int* returnVal = (t_int*)malloc(sizeof(t_int) * 2);
    t_int firstDay = -1;
    t_int lastDay = -1;

    for(t_int i = 0; i < numberOfDays; ++i)
    {
        if(daysTable[i] == actionPrice)
        {
            if( firstDay == -1 )
            {
                firstDay = i + 1;
            }
            else
            {
                lastDay = i + 1;
            }

        }
    }

    lastDay = (lastDay == -1) ? firstDay : lastDay;
    returnVal[0] = firstDay;
    returnVal[1] = lastDay;

    return returnVal;
}
t_int* fillDays(t_int numberOfDays, char* str)
{
    t_int* tabOfDays = (t_int*)malloc(sizeof(t_int) * numberOfDays);

    printf("%s", str);
//    char *pChar = strtok (str, " ");
//    int i = 0;
//    while(pChar != NULL)
//    {

//      //  tabOfDays[i] = 1;//tabOfDays[i] * 10 + pChar - '0';
//        printf("%d %s", i, pChar);
//        pChar = strtok(NULL, " ");
//        ++i;
//    }

    return tabOfDays;

}
void test_cases()
{

    t_int numberOfDays = 5;
    t_int actionPrice = 1;
    char* words = (char*)malloc(sizeof(char) * 256);

       strcpy(words, "4 3 2 1 5");
     printf(" Pokaz \n");
    t_int* tabOfDays = fillDays(numberOfDays, words);

    for(int i = 0; i < numberOfDays; ++i)
    {
        printf(" - %d", tabOfDays);
    }

    free(tabOfDays);


}

int main()
{
    srand( time(NULL) );

    test_cases();

    if( INTERFACE )
    {
                t_int numberOfDays = 1;
                t_int actionPrice = 1;
                t_int* tabOfDays;

                // printf("Podaj ilosc dni oraz cene akcji do wyszukania: ");
                scanf("%d %d", &numberOfDays, &actionPrice);
                tabOfDays = (t_int*)malloc(sizeof(t_int) * numberOfDays);
                memset(tabOfDays, 0, numberOfDays);

                // printf("\nPodaj ceny akcji w kolejnych dniach, oddzielajac spacja, zostaw puste, aby wygenerowac losowo: \n");
                getchar();
                int i = 0;
                char c;
                while ((c = getchar()) != '\n')
                {
                    if(i >= numberOfDays)
                        break;
                    if( c != ' ')
                    {
                        tabOfDays[i] = tabOfDays[i] * 10 + c - '0';
                    }
                    else
                    {
                        ++i;
                    }
                }

                if( i == 0 )
                {
                      randPrices(tabOfDays, numberOfDays);
                      for(int i = 0; i < numberOfDays; ++i)
                           printf(" %d ", tabOfDays[i]);
                }


                t_int* returnVal = getDays(numberOfDays, actionPrice, tabOfDays);

                printf(" \n%d %d", returnVal[0], returnVal[1]);
                // for(int i = 0; i < numberOfDays; ++i)
                    //     printf(" %d ", tabOfDays[i]);

                free(tabOfDays);
    }



}
s
