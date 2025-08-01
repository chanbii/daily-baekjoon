/* [1193] 분수찾기

* 문제 설명:
- 무한히 큰 배열에 행, 열 번호와 같은 분수들이 적혀있음
- 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> ... 와 같은 지그재그 순서로 나열
- X번째 분수를 구하는 프로그램을 작성
  * 입력:
	- 첫째 줄에 X가 주어짐(1 ≤ X ≤ 10,000,000)
  * 출력:
	- X번째에 해당하는 분수를 출력

* 풀이 요약:
1. 각 대각선은 1개, 2개, 3개...의 분수를 가지므로, 누적 합은 1, 3, 6, 10... 형태가 됨
2. 누적 합이 X 이상이 되는 최초의 대각선 번호를 찾음. 이 번호가 X가 속한 대각선
3. 대각선 번호가 짝수라면 분모가 크고(분자 증가, 분모 감소), 홀수면 분자가 큼(분자 감소, 분모 증가)
4. 대각선 번호를 기준으로 분자 + 분모 = 대각선 번호 + 1 관계를 활용함
5. 계산한 분수를 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int X, i, tmp = 0;
	int top, bottom;

	scanf("%d", &X);

	for (i = 1; tmp < X; i++)
		tmp += i;

	if (i % 2 == 0) { // i는 대각선 번호
		top = 1;
		bottom = i - 1;
		while (tmp != X) {
			top++;
			bottom--;
			tmp--;
		}
	}
	else {
		top = i - 1;
		bottom = 1;
		while (tmp != X) {
			top--;
			bottom++;
			tmp--;
		}
	}

	printf("%d/%d\n", top, bottom);
}