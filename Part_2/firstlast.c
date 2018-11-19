#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//////////////////////CONFIG//////////////////////
typedef int t_int;
// value for random filling
#define maxActVal 100
//switch to use interface, if off test_cases are on
#define INTERFACE false
//////////////////////////////////////////////////

void randPrices(t_int* daysTable, t_int numberOfDays)
{
    for( t_int i = 0; i < numberOfDays; ++i)
    {
        daysTable[i] = (1 + rand() % (( maxActVal + 1 ) - 1));
    }

}
bool checkResult(t_int first, t_int last, t_int* answer)
{
    if( first == answer[0] && last == answer[1] )
    {
        return true;
    }
    return false;
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

void test_cases()
{
    t_int testTab[] = {1, 3, 5, 2, 3, 4, 3};

    t_int* getD = getDays(7, 3, testTab);
    assert( checkResult(2, 7, getD) == true);
    free(getD);


    t_int testTab2[] = {2, 3, 4, 5};
    getD = getDays(4, 2, testTab2);
    assert( checkResult(1, 1, getD) == true);
    free(getD);


    t_int testTab3[] = {5, 3, 1};
    getD = getDays(3, 2, testTab3);
    assert( checkResult(-1, -1, getD) == true);
    free(getD);

}

int main()
{
    srand( time(NULL) );

    test_cases();

    if( !INTERFACE )
    {
        test_cases();
    }
    else
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
                   printf("%d ", tabOfDays[i]);
        }


        t_int* returnVal = getDays(numberOfDays, actionPrice, tabOfDays);

        printf("\n%d %d\n", returnVal[0], returnVal[1]);
        // for(int i = 0; i < numberOfDays; ++i)
            //     printf(" %d ", tabOfDays[i]);

        free(tabOfDays);
    }



}

