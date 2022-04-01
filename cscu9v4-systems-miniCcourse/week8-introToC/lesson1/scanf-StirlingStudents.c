#include <stdio.h>

int main(void)
{
    int nstudents = 0; /* initialization required */

    printf("How many students does Stirling have?\n>");
    scanf ("%d", &nstudents); /* read input */
    printf("Stirling has %d students. \n", nstudents);

    return 0;
}