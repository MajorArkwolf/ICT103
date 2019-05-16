/*-----------------------------
  Code written by Peter Crabbe
  StudentID: 32019269
  Time/Date: 1AM 24/10/12
-----------------------------*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Sets the size of the string used for user input */
const int MAXSIZE = 20;

void InitializeArray(int table[], int SIZE)
{
    /*Sets all array varibles in the table to 0 because not all parts of the string will be used*/
    int i;
    for (i=0; i < SIZE; i++)
    {
        table[i] = 0;
    }
}

int ReadInput(char line[])
{
    int i;
    /*Reads input into a string which will then be converted to lower case */
    printf("Please enter %d or less letters followed by enter: ", (MAXSIZE - 2));
	fgets(line, MAXSIZE, stdin);
	line[strlen(line) - 1] = '\0';

    for(i=0; i <= MAXSIZE; i++)
    {
       line[i] = tolower(line[i]);
    }
    return(strlen(line));
}

void CalcMatches(int table[], char line[], int length)
{
    int i;

    /* Reads the string called line and sorts it into the array called table. */
    for (i=0; i < length; i++)
    {
        /* Determines if its alphabetical and if so it will then convert it to its ascii value and sort it accordingly into the string. If however it is not alphabetical it simply adds +1 to the not-alphabetical part of the string */
        if ((int)line[i] >= 97 && (int)line[i] <= 122)
        {
            table[((int)line[i] - 97)]++;
        }
        else
        {
            table[26]++;
        }

    }
    return;
}

void PrintInfo(int table[], int SIZE)
{
    int i;
    /* This part of the script simply checks the string to see if any values other then 0 where entered into the script. If so it will +97 onto the string reverting it back to its ascii
    letter and display the letter and the data in the string occordingly. It will also display any non alphabetical letters that were entered. */
    for (i=0; i < (SIZE-1); i++)
    {
        if (table[i] > 0)
        {
            printf("\n%c was entered %d times", ((char)i+97), table[i]);
        }

    }

    if (table[26] > 0)
    {
        printf("\nCharacters other then alphabetic were entered %d times", table[26]);
    }

    return;
}

int main()
{
    /* While their is 25 letters in the alphabet I included an extra 1 in my string for any letters that are non-alphabetical */
    const int SIZE = 27;
    int table[SIZE], length;
    char line[MAXSIZE] = {'\0'};

    InitializeArray(table, SIZE);
    length = ReadInput(line);
    CalcMatches(table, line, length);
    PrintInfo(table, SIZE);

    return(0);
}
