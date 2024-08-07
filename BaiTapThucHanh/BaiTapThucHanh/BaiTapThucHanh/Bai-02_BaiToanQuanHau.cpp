/*
	
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 8

int board[N];

void printSolution() {
	for (int i = 0; i < N; i++) {
		printf("%d ", board[i] + 1);
	}
	printf("\n");
}

bool isSafe(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
			return false;
		}
	}
	return true;
}

void solveNQueens(int row) {
	if (row == N) {
		printSolution();
		return;
	}
	for (int col = 0; col < N; col++) {
		if (isSafe(row, col)) {
			board[row] = col;
			solveNQueens(row + 1);
		}
	}
}

int main() {
	solveNQueens(0);
	system("pause");
	return 0;
}
