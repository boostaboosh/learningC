//for loop squares (x*x) from 1 to 10

#include <stdio.h>

int main (void){
    //this program prints the squares from 1 to 10
    int start_num = 1;
    int end_num = 10;
    int i;
    for (i = start_num; i <= end_num; i++){
        int square = i * i;
        printf("%d * %d = %d\n", i, i, square);
    }
}