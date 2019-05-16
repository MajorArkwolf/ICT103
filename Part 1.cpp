#include <stdio.h>

void StudentInfo()
{
    /* This displays hardcoded information about the creator of this script */
    printf("\nName: Peter Crabbe\nID: 32019269\nTime: 00:00\n");
    return;
}

void GetInfo(int &input)
{
    /* Reads input from the user as a float value due to the fact it needs decimal numbers.*/
    printf("\nPlease enter a valid coin amount.\nMust be between 0-95 cents.\nMust be in 5 cent incraments.\nNumber: ");
    scanf("%d", &input);
    return;
}

void GetandValidateInput(int &cents)
{
    do
    {
        GetInfo(cents);
    }while((cents < 5 || cents > 95 || (cents % 5)!=0) && cents != 0);

    return;
}

int CalcChange(int &amount, int value)
{
    int numof;
    /* Checks if it can remove x cents and then adds to the table for each cent removed.*/
    numof = amount / value;
    amount = amount % value;

    return(numof);
}

void Result(int fiftyc, int twentyc, int tenc, int fivec)
{
    /* Displays how many coins will be given in a presentable format*/
    printf("\n50c coins total: %d\n20c coins total: %d\n10c coins total: %d\n5c  coins total: %d\n", fiftyc, twentyc, tenc, fivec);
    return;
}

int main()
{
    int fiftyc = 0, twentyc = 0, tenc = 0, fivec = 0;
    int cents;

    StudentInfo();
    GetandValidateInput(cents);

    /* Works out how many cent coins are to be given.*/
    fiftyc = CalcChange(cents, 50);
    twentyc = CalcChange(cents, 20);
    tenc = CalcChange(cents, 10);
    fivec = CalcChange(cents, 5);

    /* Prints the results for coins that need to be given */
    Result(fiftyc, twentyc, tenc, fivec);
    return(0);
}
