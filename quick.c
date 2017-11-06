#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
/* Hello */
#define MAX 10
int arr[MAX] = {122, -2, 13, 24, 0, -6, -217, 18, 19, 0};
void print() {
    int i;
    for (i = 0; i < MAX; i++) {
	printf("%d, ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int *a , int start, int end) {
    int pivot = a[end];
    int pindex = start;
    int i = 0;
	
    for (i = start; i <end; i++) {
	if (arr[i] <= pivot) {
	    swap(&arr[i], &arr[pindex]);
	    pindex++;
	}
    }
    swap(&a[end], &a[pindex]);
    return pindex;

}
void sort(int *a, int start, int end) {
    int pindex = 0;
    if (!a || start >= end)
	return;

    pindex = partition(a, start, end);

    sort(a, start, pindex-1);
    sort(a, pindex+1, end);
}

int main(int argc, char *argv[])
{
    print();
    sort(arr, 0, MAX - 1);
    print();
    return 0;
}
