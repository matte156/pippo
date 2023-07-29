#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H

typedef struct
{
    char notContained[6];
    char wrongPosition[6];
    char correctPosition[6];
} response;

// open "../usefulDataset/dataset-ascii.txt" and store it in variable "dataset". All words are
// separated by '\0' and have length=5. Return the number of words
int openDataset(char **dataset);

// check the number of time that the letter c is contained in word and return it
int contains(char c, char *word);

response compare(char *guessWord, char *targetWord);

#endif
