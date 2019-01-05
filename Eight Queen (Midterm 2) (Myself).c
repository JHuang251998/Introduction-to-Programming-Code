#include<stdio.h>
#define QUEEN 8

int q[QUEEN] = {0}; // Which column the ith row queen is.
int board[QUEEN][QUEEN] = {0};
int max;

void place(int row);
int valid(int row, int col);
int cal(void);

int main(void) {
	int K;
	int i, j;
	
	scanf("%d", &K);
	
	while(K > 0) {
		max = 0;
		
		for(i = 0; i < QUEEN; i++) {
			for(j = 0; j < QUEEN; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		
		place(0);
		printf("%d\n", max);
		
		K--;
	}
	
	return 0;
}

void place(int row) {
	int i;
	
	if(row > 8) {
		int temp = cal();
		
		if(temp > max) {
			max = temp;
		}
	}
	else {
		for(i = 0; i < QUEEN; i++) {
			if(valid(row, i)) {
				q[row] = i;
				place(row+1);
			}
		}
	}
}

int valid(int row, int col) {
	int i;
	
	for(i = 0; i < row; i++) {
		if(q[i] == col || row - i == col - q[i] || row - i == q[i] - col) {
			return 0;
		}
	}
	
	return 1;
}
// Calulate the sum.
int cal(void) {
	int count = 0;
	int i, j;
	
	for(i = 0; i < QUEEN; i++) {
		count += board[i][q[i]];
	}
	
	return count;
}
