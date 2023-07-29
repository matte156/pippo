#include<stdio.h>
#include<stdlib.h>

int openDataset(char **dataset);

int main()
{
    char *dataset;

    int nLines = openDataset(&dataset);

//    for(int i = 0; i < nLines; i++)
//	    printf("%s\n", &dataset[i*6]);
}
