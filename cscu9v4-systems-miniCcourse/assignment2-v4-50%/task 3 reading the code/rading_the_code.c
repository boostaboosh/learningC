/* Task 3: Reading the code [10] */

/*
 * Describe in detail each of the many operations and definitions that are present in the
 * following code. 
 */
int a[12] = {1, 2, 3, 4};

int main(void){
for (int i = 0;  i < (int) (sizeof(a) / sizeof(a[0]));  i++)
	  a[i] = 0;
}
