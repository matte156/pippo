#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<regex.h>
#include"commonFunctions.h"

void findAndSubstitute(char *string, char c, char *toSubstitute)
{
    char buffer[50];
    int bufferCounter = 0;
    int toSubstituteLength = strlen(toSubstitute);
    
    for(int i = 0; i < 5; i++)
    {
	if(string[i] == '.')
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
	    datasetSize = characterFilter(res->wrongPosition[i], dataset, datasetSize);
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

int main()
{
    char *dataset;

    int linecounter = openDataset(&dataset);

    response res = compare("prato", "prova");

    int newSize = filter(dataset, linecounter, &res);

    for(int i = 0; i < newSize; i++)
    {
	printf("%s\n", &dataset[i*6]);
    }

    free(dataset);
}
