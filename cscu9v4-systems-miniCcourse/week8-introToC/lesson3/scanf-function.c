#include <stdio.h>

int main (void) {
    int i, j;
    float x, y;

    i = 10;
    j = 2;

    x = 12.23;
    y = 0.01209;

    printf("i = %d\tj = %d\tx = %f\ty = %f\n\ninsert new values for integer i, integer j, float x, and float y in this order without other punctuation apart from spaces:\t", i, j, x, y);
    scanf("%d%d%f%f", &i, &j, &x, &y);
    /*
     * It is very important to remember a space after conversion specifications in the scanf
     * format string (what's between the quotes in the scanf function call) if 
     * you want to read other input symbols, like commas (,) or (+) from the input. 
     * Else, scanf will try to match the symbol (after the inputted number %d for example) 
     * from the format string with the next symbol it finds in the input stream 
     * and if it doesn't find it scanf will terminate without reading a value 
     * for the following inputs!
     */
        
    printf("\nThe new values are: \ni=%d \nj=%d \nx=%f \ny=%f", i, j, x, y);

    return 0;
}