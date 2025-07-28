/* [1011] Fly me to the Alpha Centauri

* 문제 설명:
- x지점에서 y지점으로 공간이동을 하고자 함
- 처음 속도는 1이고, 매 순간 이동 거리는 이전 속도에서 k-1 , k 혹은 k+1만큼 이동 가능
- x에서 y까지 도달하기 위해 최소 몇 번의 이동이 필요한지를 구하는 프로그램을 작성

  * 입력:
	- 첫째 줄에 테스트케이스의 개수 T가 주어짐.
    - 각각의 테스트 케이스에 대해 현재 위치 x 와 목표 위치 y 가 정수로 주어짐(x는 항상 y보다 작은 값 (0 ≤ x < y < 231))
  * 출력:
	- 각 테스트 케이스에 대해 x지점으로부터 y지점까지 정확히 도달하는데 필요한 최소한의 공간이동 장치 작동 횟수를 출력

* 풀이 요약:
1. 거리 d = y - x를 기준으로 계산
2. 최대 속도 n을 찾음 (n^2 ≤ d < (n+1)^2을 만족하는 n)
3. 세 가지 경우로 나눠 최소 작동 횟수를 결정
   - d == n^2           작동 횟수: 2n - 1
   - n^2 < d ≤ n(n+1)  작동 횟수: 2n
   - d > n(n+1)         작동 횟수: 2n + 1
4. 최소 작동 횟수 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int T, x, y, d, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &x, &y);
        d = y - x;
        n = 0;

        while (n * n <= d) {
            n++;
        }
        n--; 

        if (d == n * n)
            printf("%d\n", 2 * n - 1);
        else if (d <= n * n + n)
            printf("%d\n", 2 * n);
        else
            printf("%d\n", 2 * n + 1);
    }
}