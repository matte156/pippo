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
    
    for(int i = 0; string[i] != 0; i++)
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

int characterFilter(char c, char **dataset, int size)
{
    regex_t regex;
    char pattern[] = {c, '\0'};
    int newSize = 0;

    regcomp(&regex, pattern, REG_EXTENDED);

    for(int i = 0; i < size; i++)
	if(regexec(&regex, dataset[i], 0, NULL, 0)==0)
	    dataset[newSize++] = dataset[i];
	    // memcpy(&dataset[(newSize++)*6], &dataset[i*6], 6);

    return newSize;
}

int regexFilter(char *pattern, char **dataset, int size)
{
    regex_t regex;
    int newSize = 0;

    regcomp(&regex, pattern, REG_EXTENDED);

    for(int i = 0; i < size; i++)
	if(regexec(&regex, dataset[i], 0, NULL, 0)==0)
	    dataset[newSize++] = dataset[i];
	    // memcpy(&dataset[(newSize++)*6], &dataset[i*6], 6);

    return newSize;
}

int filter(char *dataset, int size, response *res, char ***filteredDataset)
{
    char buffer[50];
    char notContainedCharacters[5];	// list of not contained characters
    char regexBuffer[20]; 	 	// regex for exluding not contained characters
    char wrongPositionChar[5];
    int notContainedCharactersCounter = 0, wrongPositionCharCounter = 0; // number of not contained characters
    int datasetSize = size;

    char **datasetPointer = malloc(sizeof(char *) * size);
    for(int i = 0; i < size; i++)
	datasetPointer[i] = &dataset[i*6];

    buffer[0] = '^';

    for(int i = 0; i < 5; i++)
    {
	if(res->correctPosition[i] == 'X')
	    buffer[i + 1] = '.';

	if(res->correctPosition[i] != 'X')
	    buffer[i + 1] = res->correctPosition[i];

	// remove all words that have in position i that letter and store the letter in wrongPositionChar
	else if(res->wrongPosition[i] != 'X')
	{
	    sprintf(regexBuffer, ".....");
	    char regexSubBuffer[5] = "[^X]";

	    wrongPositionChar[wrongPositionCharCounter++] = res->wrongPosition[i];

	    regexBuffer[i] = 'X';
	    regexSubBuffer[2] = res->wrongPosition[i];

	    findAndSubstitute(regexBuffer, 'X', regexSubBuffer);

	    datasetSize = regexFilter(regexBuffer, datasetPointer, datasetSize);
	}
	else if(contains(res->notContained[i], res->wrongPosition) == 0)
	    notContainedCharacters[notContainedCharactersCounter++] = res->notContained[i];
    }

    if(wrongPositionCharCounter != 0)
    {
	for(int j = 0; j < wrongPositionCharCounter; j++)
	{
	    sprintf(regexBuffer, "(.*X){X}");
	    regexBuffer[3]= wrongPositionChar[j];
	    regexBuffer[6] = 1 + contains(wrongPositionChar[j], res->correctPosition) + '0';

	    datasetSize = regexFilter(regexBuffer, datasetPointer, datasetSize);
	}
    }

    if(notContainedCharactersCounter != 0)
    {
	sprintf(regexBuffer, "[^%.*s]", notContainedCharactersCounter, notContainedCharacters);
        findAndSubstitute(buffer, '.', regexBuffer);
    }
    else 
	buffer[6] = '\0';

    datasetSize = regexFilter(buffer, datasetPointer, datasetSize);
    //printf("%s", buffer);

    if(filteredDataset != NULL)
        *filteredDataset = datasetPointer;

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

	double wordEntropy = 0;

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
		//printResponse(res);
		int newSize = filter(dataset, size, &res, NULL);
		if(newSize != 0)
		{
		    double resEntropy = entropy(size, newSize);
		    // printf("New Size: %d\n",newSize);
		}
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

	printf("The entropy for the word %s is equal to\t%f\n", &dataset[i*6], wordEntropy);
    }
    return 0;
}

int main()
{
    char *dataset;
    char **filteredDataset;

    int linecounter = openDataset(&dataset);

    response res = compare("abaca", "abaca");
 
    /*int newSize = filter(dataset, linecounter, &res, &filteredDataset);
    for(int i = 0; i < newSize; i++)
	puts(filteredDataset[i]);

    for(int i = 0; i < newSize; i++)
    {
	printf("%s\n", &dataset[i*6]);
    }

    entropy(linecounter, newSize); */

    entropyBruteForce(dataset, linecounter);

    free(dataset);
    free(filteredDataset);
}
