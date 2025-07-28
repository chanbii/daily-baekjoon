/* [1436] 영화감독 숌

* 문제 설명:
- 666을 포함하여 영화 제목을 정하고자 함
- 666, 1666, 2666... 순으로 제목을 지을 때 N번째 영화의 제목을 구하는 프로그램을 작성
  * 입력:
	- 첫째 줄에 자연수 N이 주어짐(1 ≤ N ≤ 10,000)
  * 출력:
	- N번째 영화의 제목에 들어간 수를 출력

* 풀이 요약:
1. 666부터 시작하여 i를 1씩 증가시키면서 666이 들어간 수가 있으면 count를 증가시킴
2. count == N이 되면 해당 i를 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int has666(int n) {
	int count = 0;

	while (n > 0) {
		if (n % 10 == 6) {
			count++;
			if (count == 3)
				return 1;
		}
		else
			count = 0;
		n /= 10;
	}
	return 0;
}
int main(void) {
	int N, count = 0, i;

	scanf("%d", &N);

	for (i = 666; count != N; i++) {
		if (has666(i))
			count++;
	}
	printf("%d", --i);
}