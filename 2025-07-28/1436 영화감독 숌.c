/* [1436] ��ȭ���� ��

* ���� ����:
- 666�� �����Ͽ� ��ȭ ������ ���ϰ��� ��
- 666, 1666, 2666... ������ ������ ���� �� N��° ��ȭ�� ������ ���ϴ� ���α׷��� �ۼ�
  * �Է�:
	- ù° �ٿ� �ڿ��� N�� �־���(1 �� N �� 10,000)
  * ���:
	- N��° ��ȭ�� ���� �� ���� ���

* Ǯ�� ���:
1. 666���� �����Ͽ� i�� 1�� ������Ű�鼭 666�� �� ���� ������ count�� ������Ŵ
2. count == N�� �Ǹ� �ش� i�� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int has666(int n) {
	int count = 0;

	while (n > 0) {
		if (n % 10 == 6) {
			count++;
			if (count == 3)
				return 1;
		}
		else
			count = 0;
		n /= 10;
	}
	return 0;
}
int main(void) {
	int N, count = 0, i;

	scanf("%d", &N);

	for (i = 666; count != N; i++) {
		if (has666(i))
			count++;
	}
	printf("%d", --i);
}