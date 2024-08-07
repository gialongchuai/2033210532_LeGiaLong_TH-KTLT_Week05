
/*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	char str[100]; // Mang chuoi cho phep nhap toi 99 ky tu (con 1 cho ki tu ket thuc '\0')

	// Nhap chuoi
	printf("Nhap chuoi (toi da 99 ky tu): ");
	fgets(str, sizeof(str), stdin);
	// Loai bo ky tu xuong dong cuoi (neu co)
	str[strcspn(str, "\n")] = '\0';

	// In chuoi
	printf("Chuoi hien tai: %s\n", str);

	// Dao nguoc chuoi
	int len = strlen(str);
	char rev[100];

	for (int i = 0; i < len; i++) {
		rev[i] = str[len - 1 - i];
	}
	rev[len] = '\0'; // Them ky tu ket thuc chuoi

	// In chuoi dao nguoc
	printf("Chuoi sau khi dao nguoc: %s\n", rev);

	system("pause");
	return 0;
}
