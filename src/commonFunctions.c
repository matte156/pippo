#include<stdlib.h>
#include<stdio.h>

int openDataset(char **dataset)
{
    FILE *fp = fopen("usefulDataset/dataset-ascii.txt", "r");
    

    // checking number of lines
    int linecounter = 0;
    char c;
    while(((c=fgetc(fp)) == '\n' ? ++linecounter : c) != EOF)
        ;

    printf("%d\n", linecounter);

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

