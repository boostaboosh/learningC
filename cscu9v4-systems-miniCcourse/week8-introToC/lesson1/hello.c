#include <stdio.h>

/*
 * the int value is the return value,
 * argc is the argument count, 
 * argv is the argument vector (array of strings with command-line arguments)
 * if no arguments simplify int main(void)
 */
int main (int argc, char argv[])
{
    /*
     * PRINT OUT A MESSAGE
     * This comment is written on four lines
     * following the convention for longer comments (be consistent!)
     */ 
    printf("Hello World. \n \t and you ! \n Have you ever heard of \"the rock\"? \n");

    //this comment is written on one line!
    return 0; 
    //terminate the function and returns control, here 0 means no problems, 0 also stands for false
    //if no arguments, simplify exit(0);
}