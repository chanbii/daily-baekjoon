#include <vector>
#include <cstring>
using namespace std;

const int MOD = 20170805;
int dp[501][501][2];

// dp[y][x][0] : 위에서 내려와 (y,x)에 도착한 경우 수
// dp[y][x][1] : 왼쪽에서 와서 (y,x)에 도착한 경우 수

int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp, 0, sizeof(dp));

    dp[0][0][0] = 0;
    dp[0][0][1] = 1;

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (city_map[y][x] == 1) continue;
            if (y == 0 && x == 0) continue;

            if (y > 0 && city_map[y - 1][x] != 1) {
                if (city_map[y - 1][x] == 2)
                    dp[y][x][0] = dp[y - 1][x][0];
                else
                    dp[y][x][0] = (dp[y - 1][x][0] + dp[y - 1][x][1]) % MOD;
            }

            if (x > 0 && city_map[y][x - 1] != 1) {
                if (city_map[y][x - 1] == 2)
                    dp[y][x][1] = dp[y][x - 1][1];
                else
                    dp[y][x][1] = (dp[y][x - 1][0] + dp[y][x - 1][1]) % MOD;
            }
        }
    }

    return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
}
