/* Task 4: Functions and array [20] */

int *maxptr(int a[]){
    /*
     * - takes an array of positive integers as a parameter, 
     * - finds the maximum element of the array, 
     * - returns a pointer to the maximum element of the array, and 
     * - replaces the maximum element in the array with -1 (using the pointer).
     */
    
}

int main (void){
    //defines an array of 10 positive integers
    int nums[10] = {1,2,3,4,5,6,7,8,9,10};
    /* if i want the user to input the integers
    i;
    for (i=0; i<10; i++){
        int num;
        printf("Insert number %d of %d:\t", (i+1), 10);
        scanf("%d", &num);
        nums[i] = num;         
    }
    */
    
    //prints the array of 10 integers
    for (int j = 0; j < 10; j++){
        printf("number %d:\t%d\n", (j+1), nums[j]);
    }

    /*
     * Use maxptr() in a program that defines an array of 10 positive integers, prints the array,
     * calls maxptr() passing the array as a parameter and prints the returned pointer and the
     * array after the execution of maxptr().
     */
    maxptr(nums);
}