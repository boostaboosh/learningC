/* UPC (universal product code) validity checker */

/* UPC codes are 12 digits long. They consist of a sequence of 11 digits followed by a check 
 * digit.
 * For example the UPC 036000241457 has check digit 7. 
 * So if the other numbers are correct the check digit calculation must produce 7.
 * The algorithm is:
 * 
 * add the odd number digits: 0+6+0+2+1+5 = 14
 * 
 * multiply the result by 3: 14 x 3 = 42
 * 
 * add the even number digits: 3+0+0+4+4 = 11
 * 
 * add the two results together: 42 + 11 = 53
 * 
 * to calculate the check digit, take the remainder of (53 / 10), which is also known as 
 * (53 modulo 10 = 3), 
 * 
 * and subtract from 10 (10 - 3 = 7). 
 * 
 * Therefore, the check digit value is 7.
 */

#include <stdio.h>
//#include <math.h>

/* write a program that computes the check digit of an 11 digit number following the above 
 * algorithm
 */

//function that returns a digit from a number with the right most digit being digit 1
int retrieve_digit_from_right_side (long long number, int digit_wanted) {
    while (digit_wanted){
        int digit = number % 10;
        if (digit_wanted == 1) {
            return digit;
        }
        number = number / 10;
        digit_wanted --;
    } 
    return 0;
}

int is_odd(int number){
    if (number % 2 == 0) {
        return 1;
    }
    else if (number % 2 == 1) {
        return 0;
    }
}

int integer_match(int check_digit, int calc_check_digit) {
    if (check_digit == calc_check_digit) {
        return 0;
    }
    else {
        return 1;
    }
}

int main (void) {
    //int upc = 0; // int is too small!!!
    long long upc = 0;

    printf("Insert a 12 digit UPC: ");
    scanf("%lld", &upc); //i need to tell the scanner to interpret it as a lld or long long integer

    int d1=retrieve_digit_from_right_side(upc, 12), d2=retrieve_digit_from_right_side(upc, 11), d3=retrieve_digit_from_right_side(upc, 10), d4=retrieve_digit_from_right_side(upc, 9), d5=retrieve_digit_from_right_side(upc, 8), d6=retrieve_digit_from_right_side(upc, 7), d7=retrieve_digit_from_right_side(upc, 6), d8=retrieve_digit_from_right_side(upc, 5), d9=retrieve_digit_from_right_side(upc, 4), d10=retrieve_digit_from_right_side(upc, 3), d11=retrieve_digit_from_right_side(upc, 2), dcheck=retrieve_digit_from_right_side(upc, 1);

    /* this is a printf functino to check if the retrieve digit function is working well */
    printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d \n", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, dcheck);

    int eleven_digit_sequence[11] = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11};
    int eleven_sequence_counter = 11;
    
    int odd_numbers[11];
    int counter_odd = 1;

    int even_numbers[11];
    int counter_even = 1;
    
    while (eleven_sequence_counter) {
        int digit = eleven_digit_sequence[eleven_sequence_counter];
        if (is_odd(digit)) {
            odd_numbers[counter_odd] = digit;
            counter_odd ++;
        }
        else {
            even_numbers[counter_even] = digit;
            counter_even ++;
        }
        eleven_sequence_counter --;
    }  

    //add the odd number digits: 0+6+0+2+1+5 = 14
    int odd_number_sum;
    int odd_number_counter = 0;

    while (odd_number_counter < counter_odd) {
        odd_number_sum = odd_number_sum + odd_numbers[odd_number_counter];
        odd_number_counter ++;
    }
    
    //multiply the result by 3: 14 x 3 = 42
    int odd_number_sum_times3 = odd_number_sum * 3;

    //add the even number digits: 3+0+0+4+4 = 11
    int even_number_sum;
    int even_number_counter = 0;

    while (even_number_counter < counter_even) {
        even_number_sum = even_number_sum + even_numbers[even_number_counter];
        even_number_counter ++;
    }

    //add the two results together: 42 + 11 = 53
    int even_and_triple_odd_number_sum = odd_number_sum_times3 + even_number_sum;

    //to calculate the check digit, take the remainder of (53 / 10), which is also known as 
    //(53 modulo 10 = 3)
    //and subtract from 10 (10 - 3 = 7)
    //Therefore, the check digit value is 7
    int check_digit_result = 10 - (even_and_triple_odd_number_sum % 10);

    if (integer_match(dcheck, check_digit_result)) {
        printf("The UPC %lld has check digit %d.\nThis UPC is valid.\nBecause the check digit calculation results in the same check digit: %d", upc, dcheck, check_digit_result);
    } else {
        printf("The UPC %lld has check digit %d.\nThis UPC is NOT valid.\nBecause the check digit calculation results in a different check digit: %d", upc, dcheck, check_digit_result);
    }
    return 0;
}