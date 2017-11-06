#include <stdio.h>
#include <string.h>
#define MAXCNT 100
#define MAXLEN 10
#define CNT 10
#define LEN 4
char digitMatrix[CNT][LEN] = {"",
                      "",
		      "abc",
		      "def",
		      "ghi",
		      "jkl", 
		      "mno",
		      "pqrs",
		      "tuv",
		      "wxyz"};
char returnString[MAXLEN];
void letterUtil(char *string, int indexString, int digIndex, int digitLen, char *digits) {
    int i = indexString;
    int hash_len = strlen(digitMatrix[digits[digIndex]-'0']);
    char *comb = digitMatrix[digits[digIndex]-'0'];

    //printf("Calling with %d %d\n", indexString, digIndex);
    if (indexString == digitLen || digIndex == digitLen) {
	string[indexString] = '\0';
	printf("%s,", string);
	return;
    }
    if (digits[digIndex] == '0' || digits[digIndex] == '1')
	letterUtil(string, indexString, digIndex+1, digitLen, digits);
    /* try all combo with that letter*/
    for (i = 0; i < hash_len; i++) {
	string[indexString] = comb[i];
	//printf("+%c-", comb[i]);
	letterUtil(string, indexString+1, digIndex+1, digitLen, digits);
    }
   // printf("Ending with %d %d\n", indexString, digIndex);
    
}
void letterCombinations(char* digits, int len ) {

    int i = 0;
    printf("len = %d\n", len);
    returnString[len+1] = '\0';

    letterUtil(returnString, 0, 0, len, digits);
	
}

int main(int argv, char **args) {
    int i;
    char *new_string = args[1];
    for(i = 0;  i < CNT; i++) {
	printf("-%s\n-", digitMatrix[i]);
    }
    printf("%s\n", new_string); 
    letterCombinations(new_string, strlen(new_string));
    return 0;
}

