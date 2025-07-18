/* [2908] 상수

* 문제 설명:
- 두 수를 입력 받아 각 자리수를 뒤집은 다음, 더 큰 수를 출력
- 예시:
 입력 - 734 893
 출력 - 437

* 풀이 요약:
1. 입력받은 수의 각 자리를 뒤집기 위해 일의 자리부터 추출
2. 새 변수에 자릿수를 역순으로 조립 (a = a * 10 + 나머지)
3. 두 수 모두 뒤집은 뒤, 비교하여 더 큰 수 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int A, B, a = 0, b = 0;
	int i = 0;

	scanf("%d %d", &A, &B);
	
	for (i = 0; i < 3; i++) {
		a = a * 10 + (A % 10);
		b = b * 10 + (B % 10);
		A /= 10;
		B /= 10;
	}
	
	if (a > b)
		printf("%d", a);
	else
		printf("%d", b);
}