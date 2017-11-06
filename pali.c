#include <stdio.h>
#include <string.h>
#define MAXCNT 100
#define MAXLEN 10
#define CNT 10
#define LEN 4

int isPalind(char *stra, int lena, char *strb, int lenb) {
    int i = 0;

    if (!stra || !lena || !strb || !lenb || lena != lenb)
	return 0;;
    while(i < lena)
    {
	if(stra[i] != strb[i]) {
	    return 0;
	}
	i++;
    }
    return 1;
}
   
int isPalinda(char *str, int len) {
    int i = 0;

    if (!str || !len)
	return 0;;
    while(i < len/2)
    {
	if(str[i] != str[len - i - 1]) {
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
    printf("is palindrome %d\n", isPalind(new_string, strlen(new_string), new_string1, strlen(new_string1)));
    return 0;
}

