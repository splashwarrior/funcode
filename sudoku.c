#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG	1
#define LOG	1
/* Hello */
#define THREE	0
#define LEN	5
int grid[LEN][LEN];

void print_grid() {
    int i = 0, j = 0;
    printf("Current status\n");
    for(i = 0; i< LEN; i++) {
	for (j = 0; j < LEN; j++) {
	    if (grid[i][j] == -1) {
		printf("| ");
	    } else {
		printf("|%d", grid[i][j]);
	    }
	}
	printf("|\n");
    }
}

void init() {
    memset(grid, -1, sizeof(grid));
}
void setnum_at_pos(int val, int i, int j) {
    if (i >= LEN || j >= LEN)
	return;
    grid[i][j] = val;
}

int hash[LEN+1];;
void print_hash() {
#if DEBUG
#if LOG
    int i = 0;
    printf("Printing hash\n");
    for (; i < LEN; i++) {
	printf("|%d", hash[i]);
    }
    printf("\n");
#endif
#endif

}

int check_grid(int x, int y) {
    int i = 0, j = 0;

#if DEBUG
   // printf("=======START ==============================================\n");
    print_grid();
#endif
    memset(hash, 0, sizeof(hash));
    for(i = 0; i < LEN; i++) {
	if (grid[i][y] == -1) {
	} else {
	    if (hash[grid[i][y]] == 1) {
#if DEBUG
#if LOG
		print_hash();
		printf("Row loop repeat in row [%d %d] value=%d\n", i, y, grid[i][y]);
#endif
#endif
		//Repeat, fail condition
		return 0;
	    }
	    hash[grid[i][y]] = 1;
	}
    }
    memset(hash, 0, sizeof(hash));
    for(i = 0; i < LEN; i++) {
	if (grid[x][i] == -1) {
	} else {
	    if (hash[grid[x][i]] == 1) {
#if DEBUG
#if LOG
		print_hash();
		printf("Column loop repeat in row [%d %d] value=%d\n", i, y, grid[x][i]);
#endif
		//Repeat, fail condition
#endif
		return 0;
	    }
	    hash[grid[x][i]] = 1;
	}
    }
#if DEBUG
    //printf("=====================================================\n");
#endif

    return 1;
}

int solver(int x, int y) {
    int i = 0, j = 0;
    int test = 1;
    int valid = 0;
#if DEBUG
    printf("=======================SOLVER==============================\n");
    printf("\t\tSolver with [%d][%d]\n", x, y);
#endif
    if ((x == (LEN - 1)) && (y == (LEN ))) {
#if DEBUG
	printf("\n\n\t\tI SOLVED EVERYTHINGSolver with [%d][%d]\n", x, y);
#endif
	return 1;
    }
    if (x > LEN || y > LEN)
	return 0;

    for(i = x; i < LEN; i++) {
	for (j = 0; j < LEN; j++) {
	    if (grid[i][j] == -1) {
		int found_something = 0;
		for (test = 1; test <= LEN;test++) {
		    setnum_at_pos(test, i, j);
		    valid = check_grid(i, j);
		    if (!valid) {
#if DEBUG
			printf("Incorrect entry val=%d [%d][%d]\n", test, i, j);
#endif
		    } else { //found one correct lets continue
			found_something = 1;
#if DEBUG
			printf("Correct entry val=%d [%d][%d]\n", test, i, j);
#endif
			valid = solver(i, j+1);
#if DEBUG
			printf("\t\tCalling solver with[%d][%d]\n", i, j+1);
#endif
			if(valid) {
			    return 1;
			}
		    }
		    setnum_at_pos(-1, i, j);
		}
		if (found_something == 0) {
		    printf("Couldnt find anything \n");
		    return 0;
		}
		//if(!valid
		 //   setnum_at_pos(test, i, j+1);
	    }
	}
    }
    return 1;
}

int main(int argc, char *argv[])
{
    init();
   
#if THREE 
    setnum_at_pos(1, 0, 0);
    setnum_at_pos(1, 1, 1);
    setnum_at_pos(1, 2, 2);
    setnum_at_pos(2, 0, 1);
    setnum_at_pos(3, 1, 0);
#endif
#if 0//NINE 
    setnum_at_pos(9, 0, 3);
    setnum_at_pos(7, 0, 6);
    setnum_at_pos(1, 1, 0);
    setnum_at_pos(3, 1, 7);
    setnum_at_pos(5, 2, 1);
    setnum_at_pos(4, 2, 2);
    setnum_at_pos(9, 2, 7);
    setnum_at_pos(9, 3, 0);
    setnum_at_pos(6, 3, 1);
    setnum_at_pos(1, 3, 2);
    setnum_at_pos(7, 4, 8);
    setnum_at_pos(3, 5, 0);
    setnum_at_pos(5, 5, 3);
    setnum_at_pos(6, 5, 5);
    setnum_at_pos(4, 5, 7);
    setnum_at_pos(1, 6, 1);
    setnum_at_pos(2, 6, 4);
    setnum_at_pos(3, 6, 5);
    setnum_at_pos(5, 6, 7);
    setnum_at_pos(6, 6, 8);
    setnum_at_pos(6, 7, 3);
    setnum_at_pos(4, 7, 8);
    setnum_at_pos(5, 8, 2);
    setnum_at_pos(7, 8, 4);
    setnum_at_pos(2, 8, 8);
#endif
    //setnum_at_pos(3, 1, 0);
    print_grid();
    printf("\n\n");
    solver(0, 0);
    print_grid();
    return 0;
}
