/* This is a short program that reverses the order of digits on an inputted integer, 
and returns the result to the user. */

#include <stdio.h>
#include <math.h>

int main (){
    int num, num_copy, num_copy2, digit_count = 0, reversed_number;
    
    printf("Insert an integer: ");
    scanf("%d", &num);

    num_copy = num; //making a copy of inputted num so I can use it again later
    num_copy2 = num; //making another copy because I want to use it later in the output

    //first i'm going to find out how many digits are in the number
    while (num) {
        num = num / 10;
        digit_count++;
    }
    
    //must initialise reversed number before I use it in a mathematical statement later
    reversed_number = 0;

    /* Now I'm going to identify each digit starting from the right.
     * Because we are inputting and outputting a base 10 number each digit
     * represents a power of 10.
     * So, I will multiply the digit from the right of the number by the value of the base 10 
     * column in which it will go. 
     * The value of the base 10 column can be identified as the number of digits in the number 
     * minus 1, because the right most column is 10 to the power of zero.
     * Then I will repeat this process with the next digit by removing the digit we just 
     * removed from the original number.
     * So, for example the number 123 (3 digits) reversed will be:
     * 3 x 10**2 + 2 x 10**1 + 1 x 10**0 = 300 + 20 + 1 = 321
     */
    while (digit_count) {
        int right_digit = num_copy % 10; //this gives me the right most digit of the inputted number
        digit_count --; //this gives me the exponent of the base 10 column in which the first digit will go
        reversed_number = reversed_number + right_digit * (pow(10, digit_count)); //adding the first digit to our new number
        num_copy = num_copy / 10; //this gives me the number with the right most digit removed
    }

    printf("The reverse (123 -> 321) of the inputted integer %d is: %d", num_copy2, reversed_number);
    return 0;
}