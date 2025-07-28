/* [2231] 분해합

* 문제 설명:
- 자연수 N의 분해합은 M과 M을 이루는 각 자리수의 합을 의미함
- N의 분해합이 M일 경우, M을 N의 생성자라고 하며, 존재하지 않을 수도 있음
- 자연수 N이 주어졌을 때, 가장 작은 생성자를 구해내는 프로그램 작성
  * 입력:
	- 첫째 줄에 자연수 N이 주어짐(1 ≤ N ≤ 1,000,000)
  * 출력:
	- 생성자 출력(생성자가 없는 경우에는 0을 출력)

* 풀이 요약:
1. 생성자가 될 수 있는 수 중 가장 작은 수를 구함
2. 가장 작은 수부터 1씩 늘려가며 분해합이 되는 수를 찾음
3. tmpN이 0이 되면 M을 출력하며, M이 N보다 커지면 0 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N, digit = 1, tmpN, M, tmpM, i;

	scanf("%d", &N);

	tmpN = N;
	while (tmpN > 10) {
		digit++;
		tmpN /= 10;
	}
	M = N - 9 * digit - tmpN;

	if (M < 1)
		M = 1;

	tmpN = N;
	while (M <= N) {
		tmpN = N;
		tmpM = M;
		tmpN -= tmpM;
		while (tmpM > 0) {
			tmpN -= tmpM % 10;
			tmpM /= 10;
		}
		if (tmpN == 0) 
			break;
		M++;
	}

	if (M > N)   
		printf("0\n");
	else
		printf("%d\n", M);
}