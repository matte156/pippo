#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *csv = fopen("subtlex-it-filtered-ascii.csv", "r");
    FILE *normal = fopen("dataset-ascii.txt");

    int csv_line_counter = 0;
    while((fgetc() == EOF))
}
