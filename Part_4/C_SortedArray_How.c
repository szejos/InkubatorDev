#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// compare ascending
int compareAsc (const void * a, const void * b) {
     return (  *(int*)a - *(int*)b );
}

// compare descending
int compareDesc (const void * a, const void * b) {
     return (  *(int*)b - *(int*)a );
}
// checking if tabs are equal
bool tabsEqauls(const int* tab, const int* tabToComp, size_t size)
{
    for( int i = 0; i < size; ++i)
    {
        if ( tab[i] != tabToComp[i] )
        {
            return false;
        }
    }
    return true;
}
// returns -1 if sorted descending, 1 - ascending, 0 - not sorted
int howSorted(const int* tab, size_t size)
{

       int returnNum = 0;
       int* tempArrAsc = (int*)malloc(size * sizeof(int));
       int* tempArrDesc = (int*)malloc(size * sizeof(int));

       memcpy(tempArrAsc, tab, size*sizeof(int));
       memcpy(tempArrDesc, tab, size*sizeof(int));

       // sorting table ascending
       qsort(tempArrAsc, size, sizeof(int), compareAsc);
       qsort(tempArrDesc, size, sizeof(int), compareDesc);

       if( tabsEqauls(tab, tempArrAsc, size) == true )
       {
           returnNum = 1;
       }
       else if( tabsEqauls(tab, tempArrDesc, size) == true )
       {
           returnNum = -1;
       }
       else
       {
           returnNum = 0;
       }

       free(tempArrAsc);
       free(tempArrDesc);

    return returnNum;
}

void test_cases()
{

    int tab[5][8] = { {6, 4, 5, 1, 2 ,0, 2, 7}, {11, 10, 3, 2, 1, 0, 0, -1}, {5, 11, 13, 22, 111, 232, 233, 250}, {7, 8, 11, 1, 3, 111, 2323, 11}, {100, 112, 200, 1111, 2322, 2344, 2355, 2800} };

    assert( howSorted(tab[0], 8) == 0 );
    assert( howSorted(tab[1], 8) == -1 );
    assert( howSorted(tab[2], 8) == 1 );
    assert( howSorted(tab[3], 8) == 0 );
    assert( howSorted(tab[4], 8) == 1 );


}


int main()
{

    test_cases();

}

