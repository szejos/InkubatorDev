#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


char *mr_asprintf(const char *string, ...)
{
    const short MAX_SIZE = 1024;
    va_list arg;
    va_start(arg, string);
    int indeksOriginal = 0;
    int indeksReturn = 0;

    char *returnString = (char*)malloc(sizeof(char) * MAX_SIZE);
    char *tempString = (char*)malloc(sizeof(char) * MAX_SIZE);

    memset(returnString,'\0', MAX_SIZE);



    while( string[indeksOriginal] != '\0'  )
    {

        while( string[indeksOriginal] != '{' && string[indeksOriginal] != '\0' )
        {
            returnString[indeksReturn] = string[indeksOriginal];
            indeksOriginal++;
            indeksReturn++;
        }
        if ( string[indeksOriginal] == '\0' )
            break;

        indeksOriginal++;


        switch(string[indeksOriginal])
        {
            case '{':
                returnString[indeksReturn] = string[indeksOriginal];
                indeksReturn++;
                indeksOriginal++;
            break;
            case 'i':
                sprintf(tempString, "%d", va_arg(arg,int));
                strcpy(&returnString[indeksReturn], tempString);
                indeksReturn += strlen(tempString);
                indeksOriginal += 2;

            break;
            case 's':
                sprintf(tempString, "%s", va_arg(arg, char *));
                strcat(&returnString[indeksReturn], tempString);
                indeksOriginal += 2;
                indeksReturn += strlen(tempString);
            break;
        }

    }

    free(tempString);
    returnString[indeksReturn] = '\0';
    va_end(arg);
    return returnString;
}

void test_cases()
{


    char *result = mr_asprintf("Gaius Julius Caesar Augustus Germanicus");
    assert( strcmp(result, "Gaius Julius Caesar Augustus Germanicus") == 0 );
    free(result);

    result = mr_asprintf("Nickname: {s}", "Caligula");
    assert( strcmp(result, "Nickname: Caligula") == 0 );
    free(result);

    result = mr_asprintf("Reign: {i} AD - {i} AD", 37, 41);
    assert( strcmp(result, "Reign: 37 AD - 41 AD") == 0 );
    free(result);

    result = mr_asprintf("born: {s} {i}, {i} in {s} {{}", "August", 31, 12, "Antium");
    assert( strcmp(result, "born: August 31, 12 in Antium {}") == 0 );
    free(result);


}

int main(int argc, char *argv[])
{

    test_cases();

    return 0;
}

