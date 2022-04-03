#include <stdio.h>
#include <limits.h>

int main (void){
    int number_of_ints, counter;
    double min = __DBL_MAX__, max = __DBL_MIN__, avg, sum;

    printf("How many numbers? \t");
    scanf("%d", &number_of_ints);

    for (counter = 0; counter < number_of_ints; counter++){
        printf("Enter %d of %d: \t", (counter+1), number_of_ints);
        double num;
        scanf("%lf", &num);
        sum += num;
        if(num>max){
            max = num;
        }
        if(num<min){
            min=num;
        }
    }

    avg = sum/number_of_ints;

    printf("Maximum number is\t%.3lf\nMinimum number is\t%.3lf\nAverage is\t%.3lf\n", max, min, avg);

    return 0;
}