#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG	0
#define LOG	0
/* Hello */
#define THREE	0
#define LEN	9
#define INV	0
int grid[LEN][LEN];
int hashrow[LEN];
int hashcol[LEN];

void print_grid() {
    int i = 0, j = 0;
    printf("Current status\n");
    for(i = 0; i< LEN; i++) {
	for (j = 0; j < LEN; j++) {
	    if (grid[i][j] == INV) {
		printf("| ");
	    } else {
		printf("|X");
	    }
	}
	printf("|\n");
    }
}

void init() {
    memset(grid, INV, sizeof(grid));
    memset(hashcol, INV, sizeof(hashcol));
    memset(hashrow, INV, sizeof(hashrow));
}

void setnum_at_pos(int val, int i, int j) {
    if (i >= LEN || j >= LEN)
	return;
    if (val == 1) {
	grid[i][j] += 1;
	hashrow[i] += 1;
	hashcol[j] += 1;;
    } else {
	grid[i][j]--;
	hashrow[i]--;
	hashcol[j]--;;
    }
    printf("setting [%d][%d] value of hashr=%d hashc=%d\n", i, j , hashrow[i], hashcol[j]);
}

void print_hash() {
#if DEBUG
#if LOG
    int i = 0;
    printf("Printing Col hash\n");
    for (; i < LEN; i++) {
	printf("|%d", hashcol[i]);
    }
    printf("\n");
    printf("Printing Row hash\n");
    for (i = 0; i < LEN; i++) {
	printf("|%d", hashrow[i]);
    }
    printf("\n");

#endif
#endif

}
int check_diag(int x, int y) {
    int ret = 0;
    int i = 0;
    int yless = 1, ymore = 0;
    int xless = 1, xmore = 0;
    //diag cur->top left
    for (i = x-1; (i >= 0) && (y - yless >= 0); i--) {
	if (grid[i][y - yless] == 1) {
	    return  0;
	}
	yless++;
    }
    //diag cur->top right
    ymore = 1;
    for (i = x - 1; (i >= 0) && (y + ymore < LEN); i--) {
	if (grid[i][y + ymore] == 1) {
	    return 0;
	}
	ymore++;
    }
    //diag cur->bottom left
    for (i = x+1; (i < LEN) && (y - yless >= 0); i++) {
	if (grid[i][y - yless] == 1) {
	    return  0;
	}
	yless++;
    }
    //diag cur->bottom right
    ymore = 1;
    for (i = x + 1; (i < LEN ) && (y + ymore < LEN); i++) {
	if (grid[i][y + ymore] == 1) {
	    return 0;
	}
	ymore++;
    }

    return 1;
}

int check_grid(int x, int y) {

#if DEBUG
    print_grid();
#endif
    if (hashrow[x] > 1 || hashcol[y] > 1) {
	printf("really row=%d col=%d\n", hashrow[x], hashcol[y]);
	return 0;
    }
    return check_diag(x, y);;
}

int isFull(int *x, int *y) {
    int i = 0, j = 0;
    int fail = 0;
    *x = 0;
    *y = 0;
    for(i = 0; i< LEN; i++) {
	if (hashrow[i] != 1) {
	    *x = i;
	    fail = 1;
	    break;
	}
    }
    for (j = 0; j < LEN; j++) {
	if (hashcol[j] != 1) {
	    *y = j;
	    fail = 1;
	    break;
	}
    }
    if (fail) {
	return 0;
    }
    return 1;
}

int solver() {
    int i = 0, j = 0;
    int valid = 0;
    int col = 0;
#if DEBUG
    printf("=======================SOLVER==============================\n");
#endif
    if (isFull(&i, &col)) {
	printf("\n\n\t\tI SOLVED EVERYTHINGSolver with [%d][%d]\n", i, col);
	return 1;
    }
#if DEBUG
    printf("\n\n\t\tI [%d][%d]\n", i, col);
#endif

    for (j = col; j < LEN; j++) {
	setnum_at_pos(1, i, j);
	valid = check_grid(i, j);
	if (!valid) {
#if DEBUG
	    printf("Incorrect entry [%d][%d]\n",  i, j);
#endif
	} else { //found one correct lets continue
#if DEBUG
	    printf("Correct entry [%d][%d]\n", i, j);
#endif
	    valid = solver();
#if DEBUG
	    printf("\t\tCalling solver with[%d][%d]\n", i, j+1);
#endif
	    if(valid) {
		return 1;
	    }
	}
	setnum_at_pos(INV, i, j);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    init();

    print_grid();
    printf("\n\n");
    ///setnum_at_pos(1, 0, 1);
    setnum_at_pos(1, 2, 0);
    //setnum_at_pos(1, 4, 5);
    solver();
    print_grid();
    return 0;
}
