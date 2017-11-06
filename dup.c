#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
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
char  asc[256];
void dup(char str[], int len) {
   int i = 0; 
    if (!str || len < 2)
	return;

    memset(&asc, 0, sizeof(asc));
    for(i = 0; i < len; i++) {
	char c = str[i];
	int cur = c - 'a';
//	printf("%d\n", cur);
	if (asc[cur] == 1) 
	    printf("Dup:%c\n", c);
	asc[cur] = 1;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
    	printf("%s\n", argv[1]);
	dup(argv[1], strlen(argv[1]));
    }
    return 0;
}
