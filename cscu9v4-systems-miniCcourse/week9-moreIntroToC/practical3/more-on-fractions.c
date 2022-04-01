/* more on adding fractions... exercise 1 from practical 3 - practice with I/O */

#include <stdio.h>

/* making a greatest_common_factor function for calculating the greatest common factor 
 * of two numbers.
 * We need this more than once so I am making a function.
 * We will use the largest common factor to simplify fractions to irreducible fractions.
 */
int greatest_common_factor(int num1, int num2){
    int greatest_common_factor = 1; 
    /* 
     * As default we will set gcf to 1 in case we are unable to find a common factor. 
     * Because 1 is a common factor to all integers.
     */
    int divisor; //the number we divide by in arithmetic is known as the divisor
    /*
     * We will use a for loop with divisor as the counter.
     * let's make the divisor the size of num1 or num2. 
     *
     * We will check if num 1 and 2 are both 
     * divisible by the divisor. If not, we will subtract 1 from the divisor and 
     * try again. We will keep doing this until we find a number that both num 1
     * and num 2 are divisible by.
     * 
     * Once we do, we will have found the greatest common factor of num 1 
     * and num 2, because we are decreasing the size of the divisor from 
     * the largest possible number it could be, i.e. the same number as num 1 or 2.
     *
     * It doesn't matter if we choose number 1 or number 2 as the initial divisor value 
     * because to be divisible by a common number, then that common number
     * cannot be larger than either num 1 or num 2. 
     * Our loop will subtract 1 from whichever number we 
     * choose to start the divisor at, until the divisor reaches a number which is the same
     * as or less than both numbers.
     */
    for (divisor = num1; divisor > 1; divisor --){
        //we check if the divisor is a common factor
        if (num1 % divisor == 0 && num2 % divisor == 0){ 
            greatest_common_factor = divisor; //if 
            break;
        }            
    }
    return greatest_common_factor;
}

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    float decimal_result;
    char sumOrMultiply;
    char irreducible_frac_output[100];
    
    printf("Enter first fraction: ");
    scanf("%d /%d", &num1, &denom1);

    printf("Enter second fraction: ");
    scanf("%d /%d", &num2, &denom2);
    
    printf("Enter the character \"s\" if you want to sum the two fractions.\nEnter the character \"m\" if you want to multiply the two fractions.\nEntry:\t");
    scanf(" %c", &sumOrMultiply);
    /* It is very IMPORTANT to leave a space in front of the %c conversion specification in
     * the format string. Otherwise the input character you what to read will take the enter
     * value instead of the desired character value. This is because when you press enter, 
     * that is also a character.
     * This happens because unlike the %d conversion specifier which reads 
     * integers, the %c conversion specifier %c does not automatically eat whitespaces and 
     * special characters because they too are characters. To fix this you need to leave a 
     * white space before the %c char (character data type) conversion specifier, this way 
     * you tell scanf to automatically eat whitespaces and special characters, like enter!
     */

    if (sumOrMultiply == 's') {
        //summing the two fractions and outputting the result
        result_num = num1 * denom2 + num2 *denom1;
        result_denom = denom1 * denom2;
        decimal_result = (float) result_num / result_denom;

        /* 
         * to simplify fractions we need to divide both numerator 
         * and denominator by their greatest common factor.
         */ 
        int gcf = greatest_common_factor(result_num, result_denom);
        result_num = result_num / gcf;
        result_denom = result_denom / gcf;      

        printf("%d/%d + %d/%d = %d/%d or %f in decimal format\n",num1, denom1, num2, denom2, result_num, result_denom, decimal_result);
    }

    if (sumOrMultiply == 'm') {
        //multiplying the two fractions and outputting the result
        result_num = num1 * num2;
        result_denom = denom1 * denom2;
        decimal_result = (float) result_num / result_denom;    
        
        /* 
         * to simplify fractions we need to divide both numerator 
         * and denominator by their greatest common factor.
         */ 
        int gcf = greatest_common_factor(result_num, result_denom);
        result_num = result_num / gcf;
        result_denom = result_denom / gcf;  

        printf("%d/%d * %d/%d = %d/%d or %10.5f in decimal format\n",num1, denom1, num2, denom2, result_num, result_denom, decimal_result);
    }
    
    return 0;
}