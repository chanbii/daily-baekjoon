/* [1541] �Ҿ���� ��ȣ

* ���� ����:
- ������ ���� ����, +, - �θ� �����Ǿ� ����
- ��ȣ�� ������ �ļ� ���� ���� �ּҷ� ����� ���� ��ǥ
- �ٽ� ���̵��: ù '-' ���ĺ��ʹ� ��ȣ�� ��� ���� ���� ó��

- ����:
	- �Է�: 55 - 50 + 40
	- ��ȣ: 55 - (50 + 40)
	- ���: -35

* Ǯ�� ���:
1. ���ڿ��� �� ���ھ� ��ȸ�ϸ� ���ڿ� ��ȣ�� ������
2. ���ڴ� temp ������ �����Ͽ� ����
3. '+' �Ǵ� '-' ��ȣ�� ���� ���, ���ݱ��� ������ ���� temp�� total�� ���ϰų� ��
4. '-' ��ȣ�� ó�� ������ flag = 1�� �����Ͽ�, ���� ��� ���ڸ� ���� ó��
5. ������ ���ڴ� ���� ���� ���� �� �� �� ó����
6. total �� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char s[100];
	int i, temp = 0, total = 0, flag = 0;

	scanf("%s", s);

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '+') {
			if(flag)
				total -= temp;
			else
				total += temp;
			temp = 0;
		}
		else if (s[i] == '-') {
			if (flag)
				total -= temp;
			else
				total += temp;
			temp = 0;
			flag = 1;
		}
		else
			temp = temp * 10 + (s[i] - '0');
	}
	if (flag)
		total -= temp;
	else
		total += temp;

	printf("%d\n", total);
}