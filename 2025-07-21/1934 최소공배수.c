/* [1934] 최소공배수

* 문제 설명:
- 두 자연수 A와 B가 주어졌을 때, A와 B의 최소공배수를 구하는 프로그램을 작성하라

  * 입력:
	- 첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어짐 
	- 둘째 줄부터 T개의 줄에 걸쳐서 A와 B가 주어짐 (1 ≤ A, B ≤ 45,000)
  * 출력:
	- 첫째 줄부터 T개의 줄에 A와 B의 최소공배수를 입력받은 순서대로 한 줄에 하나씩 출력

* 풀이 요약:
1. 각 테스트 케이스마다 A, B 입력
2. 두 수 중 큰 수를 기준으로 시작해, 그 수에 자연수를 곱해가며 공배수를 찾음
   - A < B일 경우, B에 1부터 곱해가며 A로 나누어 떨어지는지 확인
   - 처음 나누어떨어지는 순간이 최소공배수
3. 반복을 종료하고 해당 수를 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int T, A, B, i, j;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);
		if (A < B) {
			for (j = 1; j <= A; j++)
				if (B * j % A == 0)
					break;
			printf("%d\n", B * j);
		}
		else {
			for (j = 1; j <= B; j++)
				if (A * j % B == 0)
					break;
			printf("%d\n", A * j);
		}
	}
}
