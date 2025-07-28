/* [2231] ������

* ���� ����:
- �ڿ��� N�� �������� M�� M�� �̷�� �� �ڸ����� ���� �ǹ���
- N�� �������� M�� ���, M�� N�� �����ڶ�� �ϸ�, �������� ���� ���� ����
- �ڿ��� N�� �־����� ��, ���� ���� �����ڸ� ���س��� ���α׷� �ۼ�
  * �Է�:
	- ù° �ٿ� �ڿ��� N�� �־���(1 �� N �� 1,000,000)
  * ���:
	- ������ ���(�����ڰ� ���� ��쿡�� 0�� ���)

* Ǯ�� ���:
1. �����ڰ� �� �� �ִ� �� �� ���� ���� ���� ����
2. ���� ���� ������ 1�� �÷����� �������� �Ǵ� ���� ã��
3. tmpN�� 0�� �Ǹ� M�� ����ϸ�, M�� N���� Ŀ���� 0 ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, digit = 1, tmpN, M, tmpM, i;

	scanf("%d", &N);

	tmpN = N;
	while (tmpN > 10) {
		digit++;
		tmpN /= 10;
	}
	M = N - 9 * digit - tmpN;

	if (M < 1)
		M = 1;

	tmpN = N;
	while (M <= N) {
		tmpN = N;
		tmpM = M;
		tmpN -= tmpM;
		while (tmpM > 0) {
			tmpN -= tmpM % 10;
			tmpM /= 10;
		}
		if (tmpN == 0) 
			break;
		M++;
	}

	if (M > N)   
		printf("0\n");
	else
		printf("%d\n", M);
}