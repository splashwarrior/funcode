#include <stdio.h> 
#include <stdlib.h>

/* Hello */

int funt (int x) {
    int i = 1;
    int sum = 0;
    for (i = 1; i <= x; i++) {
	if (i % 2 == 1)
	    sum = sum + i;
    }
    return sum;	
}

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 12;
    if (argc == 2) {
	int c = atoi(argv[1]);
    	printf("%d\n", funt(c));
    }

	printf("pre a=%d b=%d\n", a, b);
    if ((a = b))
	printf("a=%d b=%d\n", a, b);

    return 0;
}
