/* [1522] 문자열 교환

* 문제 설명:
- a와 b로만 이루어진 문자열이 주어질 때, a를 모두 연속으로 만들고자 함
- 문자열은 원형이므로, 처음과 끝은 서로 인접해있음
- 최소 몇 번의 교환으로 a를 연속으로 만들 수 있는지 구함
- 예시:
  - aabbaaabaaba -> 2번의 교환으로 a를 연속으로 만들 수 있음

* 풀이 요약:
1. 문자열 내 a의 개수를 셈
2. 원형 처리를 위해 문자열을 두 번 이어 붙임
3. a 개수만큼의 구간을 슬라이딩 윈도우로 탐색
4. 각 구간 내 b의 개수를 세고, 가장 작은 값을 minExchange로 저장
5. 해당 b들을 a로 바꾸면 a가 연속된 구간이 되므로, 최소 교환 횟수는 minExchange가 됨
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char s[1001];
	char copy[2001];
	int i, j;
	int a_count = 0, b_count = 0, minExchange = 1000;

	scanf("%s", s);

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == 'a')
			a_count++;

	strcpy(copy, s);   
	strcat(copy, s);

	for (i = 0; i < strlen(copy) - a_count; i++) {
		for (j = 0; j < a_count; j++)
			if (copy[i + j] == 'b')
				b_count++;
		if (minExchange > b_count)
			minExchange = b_count;
		b_count = 0;
	}
	
	printf("%d\n", minExchange);
}