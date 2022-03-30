//multiplication table from 1 to 10
#include <stdio.h>

int main(void){
    int start_num = 1;
    int end_num = 10;
    int i;
    for (i=start_num; i < end_num; i++){
        int j;
        for (j=1; j<10; j++){
            printf("%d * %d = %d\t", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}