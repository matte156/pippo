#!/bin/bash

CSV_FILE="subtlex-it-filtered-ascii.csv"
WORD_FILE="dataset-ascii.txt"

while IFS= read -r i; do
	wordToCheck=$(echo $i | sed -nE 's/^"([^"]{5})".*/\1/p')
	if grep -Fxq "$wordToCheck" $WORD_FILE
	then
		echo $i
	fi
done < $CSV_FILE
