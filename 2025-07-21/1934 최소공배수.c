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
2. 최소공배수 = (A × B) ÷ 최대공약수
3. 최대공약수는 유클리드 호제법을 이용해 구함:
     두 수 A, B에 대해 A를 B로 나눈 나머지를 계속 구하면서,
     나머지가 0이 되었을 때 나누는 수 B가 최대공약수
4. 계산한 최소공배수를 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void) {
	int T, A, B, result;

	scanf("%d", &T);

	while (T > 0) {
		scanf("%d %d", &A, &B);
		result = A * B / gcd(A, B);
		printf("%d\n", result);
		T--;
	}
}
