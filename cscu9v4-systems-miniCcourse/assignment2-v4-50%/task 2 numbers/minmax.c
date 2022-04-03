/* minmax.c numbers - task 2 - assignment 2 CSCU9V4 */

#include <stdio.h>

int main(void){
    int n;
    double min, max, avg;

    printf("Insert the number \"n\" of floating point numbers to calculate the minimum, maximum, and average of:\n"); 
    //the number of double numbers to read in and then compute the minimum, average, and maximum
    scanf("%d", &n);

    double numbers[n];

    int i;
    for (i = 0; i < n; i++){
        double num;
        printf("Insert floating point number %d of %d:\t", (i+1), n);
        scanf("%lf", &num);
        numbers[i] = num;    
    }

    //now I need to calculate the minimum, maximum, and average of my numbers!
    min = numbers[0];
    max = numbers[0];
    for (i=0; i<n; i++){
        printf("number %d of %d:\t%.3lf\n", (i+1), n, numbers[i]);
        if (numbers[i] < min){
            min = numbers[i];
        }
        if (numbers[i] > max){
            max = numbers[i];
        }
        avg = avg + numbers[i];

        if (i==(n-1)){
            avg = avg / n;
            printf("The maximum number is:\t%.3lf\nThe minimum number is:\t%.3lf\nThe average of all the numbers is:\t%.3lf\n", max, min, avg);
        }
    }

}