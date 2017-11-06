#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
/* Hello */
#define MAX 10
int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void printsum(int target)
{
    int i = 0;
    int j = 0, l = 0 , r = 0 ;
    if (target== 0) { 
	printf("nothing to find\n");
	return;
    }

    for (i = 0; i < MAX - 3; i++) {
	for (j = i + 1; j < MAX - 2; j++) {
		l = j + 1;
		r = MAX - 1;

		while (l < r) {
		    int sum = arr[i] + arr[j] + arr[l] + arr[r];
		    if (sum == target) {
			printf("sum=%d [%d,%d,%d, %d]\n", 
				target, arr[i], arr[j], arr[l], arr[r]);
			return;
		    } else if (sum < target) {
			l++;
		    } else if (sum > target) {
			r--;
		    }
		}
	}
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
    	printf("%s\n", argv[1]);
	printsum(atoi(argv[1]));
    }
    return 0;
}
