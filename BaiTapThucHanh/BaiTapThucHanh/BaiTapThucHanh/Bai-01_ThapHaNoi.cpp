/*
	
*/

#include <stdio.h>
#include <stdlib.h>
void MoveDisk(char colA, char colC) {
	printf("Chuyen dia tu cot %c sang cot %c\n", colA, colC);
}

void Tower(int n, char colA, char colB, char colC) {
	if (n == 1) {
		MoveDisk(colA, colC);
	}
	else {
		Tower(n - 1, colA, colC, colB); // Chuyen n-1 dia tu colA sang colB su dung colC lam trung gian
		MoveDisk(colA, colC);           // Chuyen dia n tu colA sang colC
		Tower(n - 1, colB, colA, colC); // Chuyen n-1 dia tu colB sang colC su dung colA lam trung gian
	}
}

int main() {
	int n;
	printf("Nhap so luong dia: ");
	scanf("%d", &n);

	Tower(n, 'A', 'B', 'C');

	system("pause");
	return 0;
}
