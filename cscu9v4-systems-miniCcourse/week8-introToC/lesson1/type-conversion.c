#include <stdio.h>

void main (void)
{
    int i, j = 12; /* i not initialized, only j */
    float f1, f2 = 1.2;

    i = (int) f2; /* explicit: i <- 1, 0.2 lost */
    f1 = i; /* implicit: f1 <- 1.0 */

    f1 = f2 + (float) j; /* explicit: f1 <- 1.2 + 12 */
    f1 = f2 + j; /* implicit: f1 <- 1.2 + 12.0 */

    //type conversion
    int x = 100000;
    short s; // -32,768...32,767

    s = x;
    printf("%d %d\n", x, s);
}