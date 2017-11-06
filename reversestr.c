#include <stdio.h>
#include <string.h>
#define MAXCNT 100
#define MAXLEN 10
#define CNT 10
#define LEN 4
void swap(char *str, int pos, int pos2) {
    char c = str[pos];
    str[pos] = str[pos2];
    str[pos2] = c;
}
void reverseStr(char *str, int len) {
    int i = 0;
    int start = 0;
    if (!str || len < 2)
	return;
    for (i = 0; i < len/2;  i++) {
	swap(str, i , len - 1 - i);
    }
}

void reverseWord(char *str, int len) {
    int i = 0;
    int start = 0;
    int j=0;

    while(str[i]!='\0')
    {
	if(str[j]==' '|| str[j]=='\0')
	{
	    reverseStr(str+i,j-i);
	    i=j+1;
	    j=i;
	}
	else
	{
	    j++;            
	}
    }
}


int main(int argv, char *args[]) {
    int i;
    char *new_string = args[1];

    printf("%s\n", new_string); 
    reverseStr(new_string, strlen(new_string));
    reverseWord(new_string, strlen(new_string));
    printf("reverse %s\n", new_string); 
    return 0;
}

