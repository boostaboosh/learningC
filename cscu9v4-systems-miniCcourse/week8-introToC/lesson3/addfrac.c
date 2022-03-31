/* The addfrac.c program prompts the user to enter two fractions and then displays their sum */

#include <stdio.h>

int main (void) {

    int numerator1;
    int numerator2;
    int denominator1;
    int denominator2;

    printf("Insert 2 fractions in the X / Y format and I will display the sum!\n");
    printf("Insert fraction 1 \"X / Y\" :\t");
    scanf("%d /%d", &numerator1, &denominator1);
    printf("Insert fraction 2 \"X / Y\" :\t");
    scanf("%d /%d", &numerator2, &denominator2);

    int lowest_common_multiple = denominator1 * denominator2;
    int new_numerator1 = (lowest_common_multiple / denominator1) * numerator1;
    int new_numerator2 = (lowest_common_multiple / denominator2) * numerator2;
    int numerator_sum = new_numerator1 + new_numerator2;

    printf("The sum of the fractions:\t%d / %d\t+\t%d / %d\t=\t%d / %d",numerator1, denominator1, numerator2, denominator2, numerator_sum, lowest_common_multiple);

    return 0;
}