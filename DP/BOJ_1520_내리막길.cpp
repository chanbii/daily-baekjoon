#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int M, N; // 세로, 가로
int mat[500][500];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int ans; // 이동 가능한 경로의 수
int dp[500][500];
// 각 지점의 높이가 빈 칸을 사이에 두고 주어진다.
// 각 지점의 높이는 10000이하의 자연수이다.

// 각 칸에는 그 지점의 높이가 쓰여 있으며, 
// 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능하다.
// 제일 왼쪽 위 칸이 나타내는 지점 -> 제일 오른쪽 아래 칸이 나타내는 지점
// 높이가 더 낮은 지점으로만 이동하여 목표 지점
// 항상 내리막길로만 이동하는 경로의 개수

// 나를 기점으로 항상 높이가 낮은 지점으로 갈 것이다.
// 4방향을 돌려서 찾을 것이다.
// 갔던 곳을 또 갈 확률이 있다, 그러면 이미 그 길은 이미 와본 것, 그 길로 가는 경우의수를
// dp에 저장한다.

int dfs(int y, int x) {
	if (y == M - 1 && x == N - 1) return 1;

	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N)
			continue;

		if (mat[y][x] <= mat[ny][nx])
			continue;

		dp[y][x] += dfs(ny, nx);
	}
	return dp[y][x];
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cin >> mat[i][j];
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0);
}
