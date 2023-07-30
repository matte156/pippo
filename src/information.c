#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<regex.h>
#include<math.h>
#include"commonFunctions.h"

void findAndSubstitute(char *string, char c, char *toSubstitute)
{
    char buffer[50];
    int bufferCounter = 0;
    int toSubstituteLength = strlen(toSubstitute);
    
    for(int i = 0; i < 5; i++)
    {
	if(string[i] == c)
	{
	    sprintf(&buffer[bufferCounter], "%s", toSubstitute);
	    bufferCounter += toSubstituteLength;
	}
	else
	    buffer[bufferCounter++] = string[i];
    }

    buffer[bufferCounter] = '\0';
    
    memcpy(string, buffer, bufferCounter + 1);
}

int characterFilter(char c, char *dataset, int size)
{
    regex_t regex;
    char pattern[] = {c, '\0'};
    int newSize = 0;

    regcomp(&regex, pattern, REG_EXTENDED);

    for(int i = 0; i < size; i++)
	if(regexec(&regex, &dataset[i*6], 0, NULL, 0)==0)
	    memcpy(&dataset[(newSize++)*6], &dataset[i*6], 6);

    return newSize;
}

int regexFilter(char *pattern, char *dataset, int size)
{
    regex_t regex;
    int newSize = 0;

    regcomp(&regex, pattern, REG_EXTENDED);

    for(int i = 0; i < size; i++)
	if(regexec(&regex, &dataset[i*6], 0, NULL, 0)==0)
	    memcpy(&dataset[(newSize++)*6], &dataset[i*6], 6);

    return newSize;
}

int filter(char *dataset, int size, response *res)
{
    char buffer[50];
    char notContainedCharacters[5];
    char notContainedCharactersRegex[9];
    int notContainedCharactersCounter = 0;
    int datasetSize = size;


    buffer[0] = '^';

    for(int i = 0; i < 5; i++)
    {
	if(res->correctPosition[i] == 'X')
	    buffer[i + 1] = '.';

	if(res->correctPosition[i] != 'X')
	    buffer[i + 1] = res->correctPosition[i];
	else if(res->wrongPosition[i] != 'X')
	{
	    char regexBuffer[10] = ".....";
	    char regexSubBuffer[5] = "[^X]";
	    datasetSize = characterFilter(res->wrongPosition[i], dataset, datasetSize);

	    regexBuffer[i] = 'X';
	    regexSubBuffer[2] = res->wrongPosition[i];

	    findAndSubstitute(regexBuffer, 'X', regexSubBuffer);

	    datasetSize = regexFilter(regexBuffer, dataset, datasetSize);
	}
	else if(contains(res->notContained[i], res->wrongPosition) == 0)
	    notContainedCharacters[notContainedCharactersCounter++] = res->notContained[i];
    }

    if(notContainedCharactersCounter != 0)
    {
	sprintf(notContainedCharactersRegex, "[^%.*s]", notContainedCharactersCounter, notContainedCharacters);
        findAndSubstitute(buffer, '.', notContainedCharactersRegex);
    }
    else 
	buffer[5] = '\0';

    datasetSize = regexFilter(buffer, dataset, datasetSize);
    //printf("%s", buffer);

    return datasetSize;
}

double entropy(int oldLength, int newLength)
{
    double probability;
    probability = (double)newLength / (double)oldLength;

    double information = -log(probability)/log(2);

    double entropy = probability*information;

    printf("Probability: %f; Information: %f; Entropy: %f\n", probability, information, entropy);

    return entropy;
}

int entropyBruteForce(char *dataset, int size)
{
    printf("\033[0m");
    response res;
    for(int i = 0; i < size; i++)
    {
	memcpy(res.notContained, &dataset[i*6], 6);
	memcpy(res.correctPosition, "XXXXX", 6);
	memcpy(res.wrongPosition, "XXXXX", 6);

	int containDoubles;

	// repeat 3^5 times
	for(int k = 0; k < 243; k++)
	{
	    containDoubles = 0;

	    for(int j = 0; j < 5; j++)
	    {
		if(res.wrongPosition[j] == 'X')
		    continue;
		if(contains(res.wrongPosition[j], res.wrongPosition) > 1)
		{
		    containDoubles = 1;
		    break;
		}
	    }

	    if(containDoubles == 0)
	    {
		printResponse(res);
	    }

	   // printResponse(res);

	    for(int j = 0; j < 5; j++)
	    {
		if(res.correctPosition[j] == 'X' && res.wrongPosition[j] == 'X')
		{
		    res.correctPosition[j] = res.notContained[j];
		    break;
		}
		else if(res.correctPosition[j] != 'X' && res.wrongPosition[j] == 'X')
		{
		    res.correctPosition[j] = 'X';
		    res.wrongPosition[j] = res.notContained[j];
		    break;
		}
		else if(res.correctPosition[j] == 'X' && res.wrongPosition[j] != 'X')
		    res.wrongPosition[j] = 'X';
	    }
	}
    }
    return 0;
}

int main()
{
    char *dataset;

    int linecounter = openDataset(&dataset);

    response res = compare("usalo", "quale");

    /*int newSize = filter(dataset, linecounter, &res);

    for(int i = 0; i < newSize; i++)
    {
	printf("%s\n", &dataset[i*6]);
    }

    entropy(linecounter, newSize); */

    entropyBruteForce(dataset, linecounter);

    free(dataset);
}
