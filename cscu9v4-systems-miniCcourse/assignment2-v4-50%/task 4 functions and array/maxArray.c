/* Task 4: Functions and array [20] */
#include <stdio.h>

int* maxptr(int a[]){

    //a variable to hold the max value
    int max = a[0];
    //declaring a pointer (variable that stores an address rather than a value) that will point to the maximum element of the array
    int* max_pointer;
    //a for loop to cycle through the elements of the array
    int i;
    for (i=0; i<10; i++){
        //if this element is bigger than the previous biggest element, make this the biggest element.
        if (a[i] > max){
            max = a[i];
            //storing the address of the maximum element of the array inn the pointer
            max_pointer = &a[i];
        }
    }
    //replacing the maximum element in the array with -1 using the pointer
    *max_pointer = -1;
    //returning the pointer to the element of the array that used to be the maximum
    return max_pointer;
}

int main (void){
    //defines an array of 10 positive integers
    int nums[10] = {1,2,3,4,50,6,7,8,9,10};

    //prints the array of 10 integers
    for (int j = 0; j < 10; j++){
        printf("number %d:\t%d\n", (j+1), nums[j]);
    }

    //calls the maxptr() passing the array as parameter
    int* max_p;
    max_p = maxptr(nums);

    //print the returned pointer
    printf("Printing the pointer:\t%p\n", max_p);

    //prints the array after the execution of maxptr()
    for (int j = 0; j < 10; j++){
        printf("number %d:\t%d\n", (j+1), nums[j]);
    }

    return 0;
}