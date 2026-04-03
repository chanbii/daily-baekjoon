#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // (n + 1)행 (m + 1)열짜리 2차원 배열을 만들고, 전부 0으로 채워라
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // (n + 1)행 (m + 1)열짜리 2차원 배열을 만들고, 전부 false로 채워라
    vector<vector<bool>> water(n + 1, vector<bool>(m + 1, false));
    
    // puddles 안에 있는 각 원소를 하나씩 꺼내서 p에 담겠다
    // p는 좌표 하나 참조만 함, 읽기 전용
    for(const auto& p:puddles){
        int x = p[0];
        int y = p[1];
        water[y][x] = true;
    }
    
    // 시작점
    dp[1][1] = 1;
    
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= m; x++){
            if(y == 1 && x == 1)
                continue;
            
            if(water[y][x])
                continue;
            
            dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]) % MOD;
        }
    }
    
    answer = dp[n][m];
    return answer;
}
