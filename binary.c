#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
/* Hello */
#define MAX 10
int arr[MAX] = {-122, -2, 1, 24, 29, 36, 37, 100, 109, 220};
void print() {
    int i;
    for (i = 0; i < MAX; i++) {
	printf("%d, ", arr[i]);
    }
    printf("\n");
}

void search(int *a, int start, int end, int num) {
    int mid = (start + end) /2 ;
    int elem = a[mid];
    if (!a || start > end)
	return;

    //printf("mid=%d valmid=%d nu =%d\n",mid, elem, num);
    if (num == elem) {
	printf("Found the element %d\n", num);
    } else if (elem > num) {
//	printf("Greater Found the element %d\n", num);
	search(a, start, mid -1, num);
    } else {
//	printf("less Found the element %d\n", num);
	search(a,mid+1, end, num);
    }
}

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    print();
    printf("Finding %d\n", num);
    search(arr, 0, MAX - 1, num);
    return 0;
}
