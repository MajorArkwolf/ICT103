/*-----------------------------
  Code written by Peter Crabbe
  StudentID: 32019269
  Time/Date: 1AM 24/10/12
-----------------------------*/
#include <stdio.h>
#include <string.h>

/* Sets the size of the string used for user input */
const int MAXSIZE = 20;

int ReadInput(char line[])
{
    int i;

    /* Reads input into a string which will then be converted to lower case */
    printf("Please enter %d or less letters followed by enter: ", (MAXSIZE - 2));
	fgets(line, MAXSIZE, stdin);
	line[strlen(line) - 1] = '\0';

    return(strlen(line));
}

void Encrpyt(char text[], int length, char cyphertext[])
{
    int i;

    for(i=0; i < length; i++)
    {
        /* The first IF statement simply converts anything between A and N in both upper and low case and adds 13 onto its ascii value therefor moving it up the alphabet. */
        if (((int)text[i] >= 65 && (int)text[i] <= 77) || ((int)text[i] >= 97 && (int)text[i] <= 109))
        {
            cyphertext[i] = (int)text[i] + 13;
        }
        else
        {
            /* The second IF statement simply removes 13 from the the ascii value because once it goes over z it returns back to A. */
            if (((int)text[i] >= 78 && (int)text[i] <= 90) || ((int)text[i] >= 110 && (int)text[i] <= 122))
            {
                cyphertext[i] = (int)text[i] - 13;
            }
            else
            {
                /* Finally anything that is not alphabetical is unchanged and passed directly into the new array as is. */
                cyphertext[i] = text[i];
            }
        }
    }
    return;
}


void DisplayEncrypted(char cyphertext[], int length)
{
    int i;
    /* Simply displays the entire message in a single line so the user can see it. */
    printf("Encrypted Message is: ");
    for (i=0; i < length; i++)
    {
        printf("%c", cyphertext[i]);
    }

	return;
}

int main()
{
    int i;
	char text[MAXSIZE] = {'\0'};
    int length;

    length = ReadInput(text);
    char cyphertext[length];

    Encrpyt(text, length, cyphertext);
	DisplayEncrypted(cyphertext, length);

	return(0);
}
