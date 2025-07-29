/* [6064] ī�� �޷�

* ���� ����:
- ī�� �޷��� M�� N�� �ֱ�� �ϴ� �� ���� ���ڰ� ���ư��� <x:y> ���·� ǥ����
- ��¥�� <1:1>���� �����ϸ�, <1:1> <2:2> <3:3> ... <M:N> ������ �ݺ���. <M:N>�� �޷��� ������ ��
- x < M �̸� x' = x + 1�̰�, �׷��� ������ x' = 1 (y < N�̸� y' = y + 1�̰�, �׷��� ������ y' = 1)
- �־��� <x:y>�� �� ��° �ظ� ��Ÿ������ ���ϴ� ���α׷��� �ۼ�

  * �Է�:
    - ù° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־���
    - �� �׽�Ʈ �����ʹ� �� �ٷ� �����Ǹ�, �� �ٿ��� �� ���� ���� M, N, x�� y�� �־���(1 �� M, N �� 40,000, 1 �� x �� M, 1 �� y �� N) 
  * ���:
    - �� �׽�Ʈ ���̽��� ���� <x:y>�� �� ��° ������ ���(��ȿ���� ���� ǥ���̶�� -1 ���)

* Ǯ�� ���:
1. M == N�� ���� (x, y) ��� ���ƾ� �ϹǷ� �ٷ� x�� ����ϰų� -1 ���
2. M�� N�� �ٸ� ���
    - M < N�� ��: y�� �������� x�� ���� (tmpX = (y - 1) % M + 1)
    - M > N�� ��: x�� �������� y�� ���� (tmpY = (x - 1) % N + 1)
3. �� �ݺ����� differ(M�� N�� ����)�� ���ϸ鼭 ��ǥ �� x �Ǵ� y�� ��ġ�ϴ��� ��
4. ��ġ�ϸ� ���� �ظ� ����� ���, �ƴ϶�� -1 ���
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int T, M, N, x, y, i, differ, j, tmpX, tmpY, found;
    
    scanf("%d", &T);

    for (i = 0; i < T; i++) {
        scanf("%d %d %d %d", &M, &N, &x, &y);

        found = 0;
        if (M == N)
            if (x == y) 
                printf("%d\n", x);
            else 
                printf("-1\n");
        else if (M < N) {
            differ = N - M;
           
            tmpX = (y - 1) % M + 1;
            for (j = 0; j < M; j++) {
                if (tmpX == x) {
                    found = 1;
                    break;
                }
                tmpX = (tmpX + differ - 1) % M + 1;
            }
            if (found)
                printf("%d\n", j * N + y);
            else
                printf("-1\n");
        }
        else {
            differ = M - N;

            tmpY = (x - 1) % N + 1;
            for (j = 0; j < N; j++) {
                if (tmpY == y) {
                    found = 1;
                    break;
                }
                tmpY = (tmpY + differ - 1) % N + 1;  
            }
            if (found)
                printf("%d\n", j * M + x);
            else
                printf("-1\n");
        }
    }
}