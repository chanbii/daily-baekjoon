/* [1541] 잃어버린 괄호

* 문제 설명:
- 수식은 양의 정수, +, - 로만 구성되어 있음
- 괄호를 적절히 쳐서 식의 값을 최소로 만드는 것이 목표
- 핵심 아이디어: 첫 '-' 이후부터는 괄호로 묶어서 전부 빼기 처리

- 예시:
	- 입력: 55 - 50 + 40
	- 괄호: 55 - (50 + 40)
	- 결과: -35

* 풀이 요약:
1. 문자열을 한 글자씩 순회하며 숫자와 기호를 구분함
2. 숫자는 temp 변수에 누적하여 조립
3. '+' 또는 '-' 기호가 나올 경우, 지금까지 조립한 숫자 temp를 total에 더하거나 뺌
4. '-' 기호를 처음 만나면 flag = 1로 설정하여, 이후 모든 숫자를 빼기 처리
5. 마지막 숫자는 루프 이후 따로 한 번 더 처리함
6. total 값 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char s[100];
	int i, temp = 0, total = 0, flag = 0;

	scanf("%s", s);

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '+') {
			if(flag)
				total -= temp;
			else
				total += temp;
			temp = 0;
		}
		else if (s[i] == '-') {
			if (flag)
				total -= temp;
			else
				total += temp;
			temp = 0;
			flag = 1;
		}
		else
			temp = temp * 10 + (s[i] - '0');
	}
	if (flag)
		total -= temp;
	else
		total += temp;

	printf("%d\n", total);
}