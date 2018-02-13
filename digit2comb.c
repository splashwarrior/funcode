//Enter a number and find number of ways it can be represetned by a=1 b =2...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCNT 100
#define MAXLEN 10
#define CNT 10
#define LEN 4
int dp[MAXLEN+1];
void init() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
}
int letterCombinations(char* str, int len ) {

    int i = 0;
    int num = 0;
    printf("len = %d\n", len);

    for ( i = 1; i < len; i++) {
	int first, second;
	first = str[i-1] - '0';;
	second = str[i] - '0';;
	printf("first=%d sec=%d\n", first, second);
	//printf("first=%d sec=%d\n", atoi(&first), atoi(&second));
	num = first*10 + second;
	printf("digit=%d\n", num);
	if (second != 0)
	    dp[i] = dp[i-1];

	if (num < 27 && first!=0) {
	    if (i > 1)
		dp[i] += dp[i-2];
	    else 
		dp[i]++;
	}
    }
    return dp[i-1];
	
}

int main(int argv, char **args) {
    int i;
    char *new_string = args[1];
    printf("%s\n", new_string); 
    init();
    printf("Combinations=%d\n", letterCombinations(new_string, strlen(new_string)));
    return 0;
}

