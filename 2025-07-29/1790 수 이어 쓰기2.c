/* [1790] 수 이어 쓰기2

* 문제 설명:
- 1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻음
- 1234567891011121314151617181920212223...
- 이렇게 만들어진 수에서, k번째 자리 숫자가 어떤 숫자인지 구하는 프로그램을 작성

  * 입력:
    - 첫째 줄에 N(1 ≤ N ≤ 100,000,000)과, k(1 ≤ k ≤ 1,000,000,000)가 주어짐
  * 출력:
    - 앞에서 k번째 자리 숫자를 출력(수의 길이가 k보다 작아서 k번째 자리 숫자가 없는 경우는 -1을 출력)

* 풀이 요약:
1. 각 자릿수에 따라 9, 90, 900 ... 순으로 숫자의 개수가 늘어남
    - i자리 수의 개수 = 9 * 10^(i-1)
    - 이 자릿수가 만들어내는 길이 = i * (9 * 10^(i-1))
2. K번째 숫자가 속한 자릿수(i)를 찾음
3. K에서 이전 자리수까지의 전체 길이를 빼서 현재 자리수 내에서의 위치를 구함
4. 해당 자리수에서 K번째 숫자가 몇 번째 숫자인지 계산
   - tmp를 현재 자리수의 최소값(10^(i-1))으로 시작
   - k > i이면 tmp를 1 증가시키고, K -= i
   - tmp가 N을 초과하면 존재하지 않으므로 -1 출력
5. tmp를 계속 10으로 나누며 앞자리부터 제거하여 K번째 수를 찾아 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    long long n, k, i, j, digit = 0, tmp, tens = 1, existence = 1;

    scanf("%lld %lld", &n, &k);

    tmp = n;
    while (tmp > 0) {
        tmp /= 10;
        digit++;
    }

    for (i = 1; i <= digit; i++) {
        tmp += i * 9 * tens;
        if (tmp >= k)
            break;
        tens *= 10;
    }

    k -= (tmp - i * 9 * tens);

    tmp = tens;
    while (k > i) {
        k -= i;
        tmp++;
        if (tmp > n) {
            existence = 0;
            break;
        }
    }
    if (existence == 0)
        printf("-1\n");
    else {
        while (i > k) {
            tmp /= 10;
            i--;
        }
        printf("%lld\n", tmp % 10);
    }
}