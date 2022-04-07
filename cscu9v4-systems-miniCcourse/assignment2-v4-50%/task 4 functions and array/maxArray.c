/* Task 4: Functions and array [20] */
#include <stdio.h>

int* maxptr(int a[]){

    //a variable to hold the max value
    int max = a[0];
    //declaring a pointer (variable that stores an address rather than a value) that will point to the maximum element of the array
    int* max_pointer = &a[0]; //Pointing to first element in array which we set as max value. If this isn't done then an array of length 1 would not have its max value pointed to by max pointer and the function would not operate as desired.
    //a for loop to cycle through the elements of the array
    int i;
    for (i=1; i<10; i++){ //index i can start at 1 because element at index 0 is already set to max value!
        //if this element is bigger than the previous biggest element, make this the biggest element.
        if (a[i] > max){
            max = a[i];
            //storing the address of the maximum element of the array in the pointer
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
    printf("array of positive integers:\n");
    for (int j = 0; j < 10; j++){
        printf("\tn%d = %d ;", (j+1), nums[j]);
    }

    //calls the maxptr() passing the array as parameter
    int* max_p = maxptr(nums);

    //print the returned pointer
    printf("\nPrinting the pointer:\t%p", max_p);

    //prints the array after the execution of maxptr()
    printf("\nthe same array after execution of maxptr():\n");
    for (int j = 0; j < 10; j++){
        printf("\tn%d = %d ;", (j+1), nums[j]);
    }

    return 0;
}