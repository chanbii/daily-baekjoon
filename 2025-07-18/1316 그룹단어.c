/* [1316] 그룹 단어 체커

* 문제 설명:
- 연속해서 나타나는 문자는 하나의 그룹으로 간주
- 이전에 나온 문자가 다시 중간에 등장하면 그룹 단어가 아님
- 예시:
  - "ccazb" → 그룹 단어
  - "kin" → 그룹 단어
  - "ccaza" → 그룹 아님 (a가 중복 등장)
  - "kink" → 그룹 아님 (k가 떨어져 있음)

* 풀이 요약:
1. 단어를 문자 배열로 입력받음
2. 문자 변경이 감지될 때마다 이전 문자를 추적용 배열에 저장
3. 이후 같은 문자가 나오면 그룹 단어가 아님
4. 조건에 맞으면 count++
5. 마지막에 count 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_in(char s[], char c) {
	int i;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return 1;
	return 0;
}

int isGroupWord(char s[]) {
	int i, j = 0;
	char seen[100]; // 지금까지 나온 문자를 저장하는 배열

	for (i = 1; s[i] != '\0'; i++) 
		if (s[i - 1] != s[i]) {
			seen[j++] = s[i - 1];
			seen[j] = '\0';

			if (is_in(seen, s[i]))
				return 0;
		}

	return 1;
}

int main(void) {
	int n, i;
	char s[100];
	int count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", s);
		if (isGroupWord(s))
			count++;
	}
	printf("%d", count);
}
