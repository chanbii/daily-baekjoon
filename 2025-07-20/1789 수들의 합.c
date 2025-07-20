/* [1789] 수들의 합

* 문제 설명:
- 서로 다른 N개의 자연수의 합이 S일 때, 만들 수 있는 자연수 N의 최댓값을 구하라

  * 입력:
	- 첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어짐
  * 출력:
	- 만들 수 있는 자연수 N의 최댓값

* 풀이 요약:
1. i = 1부터 시작해서, S에서 계속 i를 차례로 빼나감
2. 뺄 수 있을 때까지 반복하면서 i를 증가시킴
3. 더 이상 뺄 수 없는 순간의 i값 - 1이 최대 개수 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned int s, i;

	scanf("%d", &s);

	for (i = 1; i <= s; i++)
		s -= i;

	i--;
	printf("%d", i);
}
