#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct
{
    char notContained[5];
    char wrongPosition[5];
    char correctPosition[5];
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
	res.correctPosition[i] = guessWord[i] == targetWord[i] ? targetWord[i] : -1;
	res.wrongPosition[i] = contains(guessWord[i], targetWord) == 1 ? guessWord[i] : -1;
    }

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
    while(1)
    {
	printf("> ");
	int counter = 0;
	char input[6], c;
	while((input[counter++] = getchar()) != '\n' && counter < 6)
	    ;
	while(input[5] != '\n' && getchar() != '\n');
	input[5] = '\0';

	if(input[0] == EOF)
	    return 0;

	int valid = 1;
	for(int i = 0; i < 5; i++)
	    if(!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')))
		valid = 0;

	if(valid == 0)
	    continue;

	response res = compare(input, &dataset[wordPosition*6]);

	for(int i = 0; i < 5; i++)
	{
	    if(res.correctPosition[i] != -1)
		printf("\033[0:32m%c\033[0m", res.correctPosition[i]);
	    else if(res.wrongPosition[i] != -1)
		printf("\033[0:33m%c\033[0m", res.wrongPosition[i]);
	    else
		putchar(input[i]);
	}
	putchar('\n');
//	printf("Word %s %s\n", input, checkWordExistence(input, dataset, size) == 1 ? "exist" : "not exist");
    }
}

int main()
{
	FILE *fp = fopen("dataset-ascii.txt", "r");

	int linecounter = 0;
	char c;
/*	while(1)
		putchar((c=fgetc(fp))==EOF ? EOF : c);

	return 0;*/
	while(((c=fgetc(fp)) == '\n' ? ++linecounter : c) != EOF)
		;
	
	char *dataset = malloc(sizeof(char)*(linecounter*6) + 1);
	fseek(fp, 0, SEEK_SET);

	int counter= 0;
	while((dataset[counter++] = (c=fgetc(fp))=='\n' ? '\0' : c)!=EOF)
		;

	srand(time(NULL));
	int wordIndex = rand() % linecounter;
	fclose(fp);

	shell(wordIndex, dataset, linecounter);
}
