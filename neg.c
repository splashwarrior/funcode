#include <stdio.h> 
#include <stdlib.h>

/* Hello */

int funt (int x) {
    int negx = ~x +1;
    return negx;	
}
int findBig(int a, int b) {

    int test =  0;
    int arr[2] = {a, b};;
    int mask = (((sizeof(int))<<3) - 1);

    test = a - b;

    test = (test >> mask) ;
    printf("Method 1 %d \m",  (a & ~test) | (b & test));
    printf("Method 2 %d ]n", a ^ ((a ^ b) & mask);
    //test = (test >> mask) & 1;

    printf("test=%d sizeof(%d)\n", test, (int)sizeof(int));
    //printf("intmax=%d intmin(%d)\n", INT_MAX, INT_MIN); 
    return arr[(int)test];
    


}

int main(int argc, char *argv[])
{
    if (argc == 3) {
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
    	printf("num=%d num=%d greater=%d  \n", a, b, findBig(a,b));
    	//printf("num=%d neg=%d mask=%d\n", c, funt(c), (funt(c)>>31) &1);
    }
    return 0;
}
