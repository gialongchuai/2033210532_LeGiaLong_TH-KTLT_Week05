/*
	
*/

#include <stdio.h>
#include <stdlib.h>

// Kich thuoc cua ban co
#define N 8

// Mang de luu cac buoc di hop le cua quan ma
int X[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Kiem tra xem vi tri (x, y) co nam trong ban co va chua duoc di qua khong
int hopLe(int x, int y, int banCo[N][N]) {
	return (x >= 0 && x < N && y >= 0 && y < N && banCo[x][y] == -1);
}

// Ham de quy de tim duong di cua quan ma
int timDuongDi(int x, int y, int buocDi, int banCo[N][N], int X[], int Y[]) {
	int buocKeTiep_x, buocKeTiep_y;
	if (buocDi == N*N) {
		return 1;
	}

	for (int i = 0; i < 8; i++) {
		buocKeTiep_x = x + X[i];
		buocKeTiep_y = y + Y[i];
		if (hopLe(buocKeTiep_x, buocKeTiep_y, banCo)) {
			banCo[buocKeTiep_x][buocKeTiep_y] = buocDi;
			if (timDuongDi(buocKeTiep_x, buocKeTiep_y, buocDi + 1, banCo, X, Y) == 1) {
				return 1;
			}
			else {
				banCo[buocKeTiep_x][buocKeTiep_y] = -1; // backtracking
			}
		}
	}
	return 0;
}

// In ban co sau khi da tim duoc duong di
void inBanCo(int banCo[N][N]) {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			printf(" %2d ", banCo[x][y]);
		}
		printf("\n");
	}
}

int main() {
	// Khoi tao ban co
	int banCo[N][N];
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			banCo[x][y] = -1;
		}
	}

	// Vi tri bat dau
	int x = 0, y = 0;
	banCo[x][y] = 0; // Buoc di dau tien

	// Tim duong di cua quan ma
	if (timDuongDi(x, y, 1, banCo, X, Y) == 0) {
		printf("Khong tim duoc duong di.\n");
	}
	else {
		inBanCo(banCo);
	}

	system("pause");
	return 0;
}
