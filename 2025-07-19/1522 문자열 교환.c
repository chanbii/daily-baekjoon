/* [1522] ���ڿ� ��ȯ

* ���� ����:
- a�� b�θ� �̷���� ���ڿ��� �־��� ��, a�� ��� �������� ������� ��
- ���ڿ��� �����̹Ƿ�, ó���� ���� ���� ����������
- �ּ� �� ���� ��ȯ���� a�� �������� ���� �� �ִ��� ����
- ����:
  - aabbaaabaaba -> 2���� ��ȯ���� a�� �������� ���� �� ����

* Ǯ�� ���:
1. ���ڿ� �� a�� ������ ��
2. ���� ó���� ���� ���ڿ��� �� �� �̾� ����
3. a ������ŭ�� ������ �����̵� ������� Ž��
4. �� ���� �� b�� ������ ����, ���� ���� ���� minExchange�� ����
5. �ش� b���� a�� �ٲٸ� a�� ���ӵ� ������ �ǹǷ�, �ּ� ��ȯ Ƚ���� minExchange�� ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char s[1001];
	char copy[2001];
	int i, j;
	int a_count = 0, b_count = 0, minExchange = 1000;

	scanf("%s", s);

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == 'a')
			a_count++;

	strcpy(copy, s);   
	strcat(copy, s);

	for (i = 0; i < strlen(copy) - a_count; i++) {
		for (j = 0; j < a_count; j++)
			if (copy[i + j] == 'b')
				b_count++;
		if (minExchange > b_count)
			minExchange = b_count;
		b_count = 0;
	}
	
	printf("%d\n", minExchange);
}