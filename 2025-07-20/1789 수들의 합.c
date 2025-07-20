/* [1789] 수들의 합

* 문제 설명:
- 서로 다른 N개의 자연수의 합이 S일 때, 만들 수 있는 자연수 N의 최댓값을 구하라

  * 입력:
	- 첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어짐
  * 출력:
	- 만들 수 있는 자연수 N의 최댓값

* 풀이 요약:
1. 자연수 N개를 더한 값은 1 + 2 + ... + n = n(n+1)/2
2. n(n+1)/2 ≤ S 를 만족하는 n의 최댓값을 구함
3. while문을 통해 위 조건을 만족하는 n까지 증가시킨 뒤, n - 1 출력 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long s, n = 1;

	scanf("%lld", &s);

	while (n * (n + 1) / 2 <= s)
		n++;

	printf("%lld\n", n - 1);
}
