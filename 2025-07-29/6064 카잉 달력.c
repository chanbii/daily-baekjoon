/* [6064] 카잉 달력

* 문제 설명:
- 카잉 달력은 M과 N을 주기로 하는 두 개의 숫자가 돌아가며 <x:y> 형태로 표현됨
- 날짜는 <1:1>부터 시작하며, <1:1> <2:2> <3:3> ... <M:N> 순으로 반복됨. <M:N>이 달력의 마지막 해
- x < M 이면 x' = x + 1이고, 그렇지 않으면 x' = 1 (y < N이면 y' = y + 1이고, 그렇지 않으면 y' = 1)
- 주어진 <x:y>가 몇 번째 해를 나타내는지 구하는 프로그램을 작성

  * 입력:
    - 첫째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어짐
    - 각 테스트 데이터는 한 줄로 구성되며, 각 줄에는 네 개의 정수 M, N, x와 y가 주어짐(1 ≤ M, N ≤ 40,000, 1 ≤ x ≤ M, 1 ≤ y ≤ N) 
  * 출력:
    - 각 테스트 케이스에 대해 <x:y>가 몇 번째 해인지 출력(유효하지 않은 표현이라면 -1 출력)

* 풀이 요약:
1. M == N인 경우는 (x, y) 모두 같아야 하므로 바로 x를 출력하거나 -1 출력
2. M과 N이 다를 경우
    - M < N일 때: y를 기준으로 x를 맞춤 (tmpX = (y - 1) % M + 1)
    - M > N일 때: x를 기준으로 y를 맞춤 (tmpY = (x - 1) % N + 1)
3. 각 반복마다 differ(M과 N의 차이)를 더하면서 목표 값 x 또는 y와 일치하는지 비교
4. 일치하면 현재 해를 계산해 출력, 아니라면 -1 출력
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