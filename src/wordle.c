#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"commonFunctions.h"

int shell(int wordPosition, char *dataset, int size)
{
    int attempts = 0;
    while(attempts < 6)
    {
	printf("%d> ", attempts + 1);
	int counter = 0;
	char input[6], c;

	while((input[counter++] = getchar()) != '\n' && counter < 6)
	{
	    if(input[counter-1] == EOF)
	    {
		putchar('\n');
	        return 0;
	    }
	}

	int valid = 1;
	
	// clear stdin
	while(counter == 6 && input[5] != '\n' && getchar() != '\n') valid = 0;
	if(valid == 0 || counter != 6)
	{
	    printf("\033[0;31mLa parola deve essere di 5 lettere\033[0m\n");
	    continue;
	}

	// termina la stringa con \0
	input[5] = '\0';
	
	// check if word typed in is correct
	valid = 1;
	for(int i = 0; i < 5; i++)
	    if(!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')))
		valid = 0;

	valid = 1; // to debug
	if(valid == 0)
	{
	    printf("\033[0;31mInserisci una parola reale\033[0m\n");
	    continue;
	}

	response res = compare(input, &dataset[wordPosition*6]);

	for(int i = 0; i < 5; i++)
	{
	    if(res.correctPosition[i] != 'X')
		printf("\033[32;1;1m%c\033[0m", res.correctPosition[i]);
	    else if(res.wrongPosition[i] != 'X')
		printf("\033[33;1m%c\033[0m", res.wrongPosition[i]);
	    else
		putchar(input[i]);
	}
	putchar('\n');

	if(strcmp(input, &dataset[wordPosition*6]) == 0)
	{
	    printf("Hai vinto!\n");
	    return 0;
	}
	if(attempts == 5)
	{
	    printf("Hai perso!\n");
	    return 1;
	}

	attempts++;

    }
    return 0;
}

int main()
{
    printf("\033[0m");
    
    char *dataset;
    int linecounter = openDataset(&dataset);

    srand(time(NULL));
    int wordIndex = rand() % linecounter;

    char debugWord[] = "prova";
    shell(0, debugWord, 1);
//    shell(wordIndex, dataset, linecounter);

    free(dataset);
}
