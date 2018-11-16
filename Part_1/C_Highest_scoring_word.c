#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// function to calculate the score of a word
int wordScore(char* word)
{
    unsigned int score = 0;
    unsigned int length = strlen(word);
    for(int i = 0; i < length; ++i)
    {
        //word[i] = tolower(word[i]);

        //substract 96, since "a" is 97 in ASCII
        score += word[i] - '`';
    }
    return score;
}


char* highestScoringWord(char* word)
{
   char* highWord = NULL;
   unsigned int actScore = 0;
   unsigned int highScore = 0;
   char* pChar;

   pChar = strtok (word, " ");
   while(pChar != NULL)
   {
       actScore = wordScore(pChar);
       if( actScore > highScore )
       {
           highScore = actScore;
           highWord = pChar;
       }
       pChar = strtok(NULL, " ");
   }

   return highWord;
}

void test_cases()
{
    char* words = (char*)malloc(sizeof(char) * 256);

    strcpy(words, "ala ma kota");
    char* answer = highestScoringWord(words);
    assert( strcmp(answer, "kota") == 0 );


    strcpy(words, "alzz ma kota");
    answer = highestScoringWord(words);
    assert( strcmp(answer, "alzz") == 0 );

    strcpy(words, "czapka czeresni");
    answer = highestScoringWord(words);
    assert( strcmp(answer, "czeresni") == 0 );

    free(words);

}

int main(int argc, char *argv[])
{

    test_cases();

    return 0;
}

