#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<regex.h>
#include<math.h>
#include<omp.h>
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

int removeDuplicates(char *s)
{
    int sorted = 0, arrayCounter = 1;

    while(sorted == 0)
    {
	sorted = 1;
	for(int i = 0; i < 4; i++)
	{
	    if(s[i + 1] < s[i])
	    {
		sorted = 0;
		int buf = s[i];
		
		s[i] = s[i + 1];
		s[i + 1] = buf;
	    }
	}
    }
    for(int i = 1; i < 5; i++)
    {
	if(s[i] != s[i - 1])
	    s[arrayCounter++] = s[i];
    }

    s[arrayCounter] = '\0';

    return 0;
}

int filterRegex(char **dataset, int size, char *pattern)
{
    int counter = 0;
    regex_t regex;

    regcomp(&regex, pattern, REG_EXTENDED);

    for(int i = 0; i < size; i++)
    {
	if(regexec(&regex, dataset[i], 0, NULL, 0))
	    dataset[counter++] = dataset[i];
    }

    return counter;
}

int filter(char *dataset, int size, response *res)
{
    char notContainedChar[6];
    char regexBuffer[50] = ".....", regexSubBuffer[10];
    int counter = 0, datasetSize = size;

    char **datasetPtr = malloc(sizeof(char)*size);
    if(datasetPtr == NULL)
    {
	fprintf(stderr, "Error allocating memory\nAborting...\n");
	exit(1);
    }

    for(int i = 0; i < size; i++)
	datasetPtr[i] = &dataset[i*6];

    memcpy(notContainedChar, res, 6);

    removeDuplicates(notContainedChar);

    for(int i = 0; notContainedChar[i] != '\0'; i++)
    {
	if(contains(notContainedChar[i], res->wrongPosition) == 0)
	    notContainedChar[counter++] = notContainedChar[i];
    }
    notContainedChar[counter] = '\0';

    sprintf(regexSubBuffer, "[^%s]", notContainedChar);

    for(int i = 0; i < 5; i++)
	regexBuffer[i] = res->correctPosition[i] != 'X' ? res->correctPosition[i] : 'X';

    findAndSubstitute(regexBuffer, 'X', regexSubBuffer);

    datasetSize = filterRegex(datasetPtr, datasetSize, regexBuffer);


    for(int i = 0; i < 5; i++)
    {
	if(res->wrongPosition[i] != 'X')
	{

	}
    }

    free(datasetPtr);

    return 0;
}

int main()
{ 
    char *dataset;
    int size = openDataset(&dataset);

    #pragma omp parallel
    {
	//provaFilter(dataset, size);
    }

    char prova[] = "pippo";
    char *provaAdress = prova;

    removeDuplicates(prova);

    response res = compare("prato", "prova");

    filter(dataset, size, &res);

    free(dataset);
}
