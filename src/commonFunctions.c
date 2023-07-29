#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"commonFunctions.h"

int contains(char c, char *word)
{
    int numberOfLettersContained = 0;
    for(int i = 0; i < 5; i++)
	if(c==word[i])
	    numberOfLettersContained++;
    return numberOfLettersContained;
}

response compare(char *guessWord, char *targetWord)
{
    response res;
    for(int i = 0; i < 5; i++)
	res.correctPosition[i] = guessWord[i] == targetWord[i] ? targetWord[i] : 'X';

    for(int i = 0; i < 5; i++)
	res.wrongPosition[i] = (contains(guessWord[i], targetWord) - 
			       contains(guessWord[i], res.correctPosition) -
			       contains(guessWord[i], res.wrongPosition)) > 0 &&
	       		       res.correctPosition[i] == 'X' &&
			       contains(guessWord[i], res.wrongPosition) == 0 ? guessWord[i] : 'X';

    res.correctPosition[5] = res.wrongPosition[5] = '\0';

    memcpy(res.notContained, guessWord, 6*sizeof(char));

    return res;
}

int openDataset(char **dataset)
{
    FILE *fp = fopen("usefulDataset/dataset-ascii.txt", "r");
    

    // checking number of lines
    int linecounter = 0;
    char c;
    while(((c=fgetc(fp)) == '\n' ? ++linecounter : c) != EOF)
        ;

    // putting all words in a database separated by a null character
    *dataset = malloc(sizeof(char)*(linecounter*6) + 1);

    fseek(fp, 0, SEEK_SET);

    int counter= 0;
    *dataset[0] = 'a';

/*    while(( *dataset[counter++] = (c=fgetc(fp))=='\n' ? '\0' : c)!=EOF)
        ;*/

    while(((*dataset)[counter++] = (c=fgetc(fp))=='\n' ? '\0' : c)!=EOF)
        ;
    
    fclose(fp);

    return linecounter;
}

