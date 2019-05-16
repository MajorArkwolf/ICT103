#include <stdio.h>

void StudentInfo()
{
    /* This displays hardcoded information about the creator of this script */
    printf("\nName: Peter Crabbe\nID: 32019269\nTime: 00:00\n");
    return;
}

void GetInfo(double &input)
{
    /* Reads input from the user as a float value due to the fact it needs decimal numbers.*/
    printf("\nPlease enter a valid coin amount.\nMust be between 0-95 cents.\nMust be in 5 cent incraments.\nNumber: ");
    scanf("%lf", &input);
    return;
}

void ConvertInfo(double change, int &dollars, int &cents)
{
    /* Does 2 differant error checks, Checks first to make sure its in a valid cent range and then second it checks to make sure its a valid cent.*/
    dollars = (int)change;
    cents = (int)(((change - dollars)*100) + 0.5);
    return;
}

void GetandValidateInput(int &dollars, int &cents)
{
    double change;
    do
    {
        GetInfo(change);
        ConvertInfo(change, dollars, cents);
        /* I added a not if 0 because even if there is 0 cents its still valid and should continue.*/
    }while((cents < 5 || cents > 95 || (cents % 5)!=0) && (cents != 0 || dollars <=0));

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

void Results(int onehundreedd, int fiftyd, int twentyd, int tend, int fived, int twod, int oned, int fiftyc, int twentyc, int tenc, int fivec)
{
/* Displays how many coins will be given in a presentable format*/
    printf("\n\n$100 notes total: %d\n$50  notes total: %d\n$20  notes total: %d\n$10  notes total: %d\n$5   notes total: %d\n$2   coins total: %d\n$1   coins total: %d\n\n50c  coins total: %d\n20c  coins total: %d\n10c  coins total: %d\n5c   coins total: %d\n", onehundreedd, fiftyd, twentyd, tend, fived, twod, oned, fiftyc, twentyc, tenc, fivec);
    return;
}

int main()
{
    int dollars, cents;
    int onehundreedd = 0, fiftyd = 0, twentyd = 0, tend = 0, fived = 0, twod = 0, oned = 0, fiftyc = 0, twentyc = 0, tenc = 0, fivec = 0;

    StudentInfo();
    /* Do loop is to get a input then check to make sure a valid input was entered, it will keep looping until a valid input is entered.*/
    GetandValidateInput(dollars, cents);

    /* Works out how many dollar coins/notes are to be given.*/
    onehundreedd = CalcChange(dollars, 100);
    fiftyd = CalcChange(dollars, 50);
    twentyd = CalcChange(dollars, 20);
    tend = CalcChange(dollars, 10);
    fived = CalcChange(dollars, 5);
    twod = CalcChange(dollars, 2);
    oned = CalcChange(dollars, 1);
    fiftyc = CalcChange(cents, 50);
    twentyc = CalcChange(cents, 20);
    tenc = CalcChange(cents, 10);
    fivec = CalcChange(cents, 5);

    /* Prints the results for both dollars and coins that need to be given */
    Results(onehundreedd, fiftyd, twentyd, tend, fived, twod, oned, fiftyc, twentyc, tenc, fivec);
    return(0);
}
