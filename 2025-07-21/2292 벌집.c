#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/*1 7 13 19 25
		1 3 9 15 21 4�� ���̳���... ?
		1 7 19 37 61
		6 12 18 24  13�̴� ->
		1����  19���� ������ ���ڳ�
		*/
	int n, roomNum = 1, count = 1;

	scanf("%d", &n);

	while (n > roomNum)
		roomNum += 6 * count++;
	printf("%d", count);
}
