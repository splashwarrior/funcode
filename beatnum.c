#include <stdio.h>
#include <string.h>
#define MAXCNT 100
#define MAXLEN 10
#define CNT 10
#define LEN 4

#define MIN(a, b) ((a) > (b) ? (b) : (a))
int compPrefix(char *stra, int lena, char *strb, int lenb) {
    int i = 0;

    if (!stra || !lena || !strb || !lenb) 
	return 0;;
    lena = MIN(lena, lenb);
    while(i < lena)
    {
	if(stra[i] != strb[i]) {
	    return 0;
	}
	i++;
    }
    return 1;
}
   
int main(int argv, char *args[]) {
    int i;
    char *new_string = args[1];
    char *new_string1 = args[2];

    printf("%s %s\n", new_string, new_string1); 
    printf("is suffix %d\n", compPrefix(new_string, strlen(new_string), new_string1, strlen(new_string1)));
    return 0;
}

