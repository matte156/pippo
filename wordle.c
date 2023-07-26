#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct
{
    char notContained[6];
    char wrongPosition[6];
    char correctPosition[6];
} response;

int contains(char c, char *word)
{
    for(int i = 0; i < 5; i++)
	if(c==word[i])
	    return 1;
    return 0;
}

response compare(char *guessWord, char *targetWord)
{
    response res;
    for(int i = 0; i < 5; i++)
    {
	res.correctPosition[i] = guessWord[i] == targetWord[i] ? targetWord[i] : 'X';
	res.wrongPosition[i] = contains(guessWord[i], targetWord) == 1 && contains(guessWord[i], res.correctPosition) == 0 ? guessWord[i] : 'X';
    }
    res.correctPosition[5] = res.wrongPosition[5] = '\0';

    return res;
}

int max(char *w1, char *w2)
{
    for(int i = 0; i < 5; i++)
    {
	if(w1[i] > w2[i])
	    return(1);
	else if(w1[i] < w2[i])
	    return(2);
    }
    return 0;
}

int checkWordExistence(char *word, char *dataset, int size)
{
    int left = 0, right = size;

    while(left <= right)
    {
	int pivot = left + (right-left)/2;
	
	if(max(word, &dataset[pivot*6]) == 0)
	    return 1;
	else if(max(word, &dataset[pivot*6]) == 1)
	    left = pivot + 1;
	else if(max(word, &dataset[pivot*6]) == 2) 
	    right = pivot - 1;
    }

    return 0;
}

int shell(int wordPosition, char *dataset, int size)
{
    int attempts = 0;
    while(attempts < 6)
    {
	printf("%d> ", attempts);
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
    puts("\033[0m");
    FILE *fp = fopen("dataset-ascii.txt", "r");

    // checking number of lines
    int linecounter = 0;
    char c;
    while(((c=fgetc(fp)) == '\n' ? ++linecounter : c) != EOF)
	;

    // putting all words in a database separated by a null character
    char *dataset = malloc(sizeof(char)*(linecounter*6) + 1);
    fseek(fp, 0, SEEK_SET);
    int counter= 0;
    while((dataset[counter++] = (c=fgetc(fp))=='\n' ? '\0' : c)!=EOF)
    	;
    fclose(fp);

    srand(time(NULL));
    int wordIndex = rand() % linecounter;

    char debugWord[] = "tonfo";
    shell(0, debugWord, 1);

    free(dataset);
    //	shell(wordIndex, dataset, linecounter);
}
