/* more on adding fractions... exercise 1 from practical 3 - practice with I/O */

#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    char addOrMultiply;
    
    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &denom1);

    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &denom2);
    
    printf("Enter the character \"a\" if you want to add the two fractions.\nEnter the character \"m\" if you want to multiply the two fractions.\nEntry:\t");
    scanf("%c", &addOrMultiply);

    if (addOrMultiply == 's') {
        //summing the two fractions and outputting the result
        result_num = num1 * denom2 + num2 *denom1;
        result_denom = denom1 * denom2;
        printf("The sum is %d/%d\n",result_num, result_denom);
    }

    if (addOrMultiply == 'm') {
        //multiplying the two fractions and outputting the result
        result_num = num1 * num2;
        result_denom = denom1 * denom2;
        printf("The product is %d/%d\n",result_num, result_denom);
    }
    
    return 0;
}