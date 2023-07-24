#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
}
