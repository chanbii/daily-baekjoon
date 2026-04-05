#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 방향성이 없는 그래프가 주어진다
// 1번 정점에서 N번 정점까지 최단 거리 이동
// 두 정점은 반드시 통과
// 1 -> A -> B -> N
// 1 -> B -> A -> N
// 반드시 최단 경로!
// 간선에 거리가 있음

struct Edge {
	int to, cost;
	bool operator<(Edge right)const {
		return cost > right.cost;
	}
};

int N, E; // 정점의 개수와 간선의 개수
int dist[801];
vector<Edge> edges[801];
int A, B;
const int INF = 21e8;

void dijkstra(int start, int cost) {
	// 1. 사전 설정
	priority_queue<Edge> pq;
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	// 2. 시작 노드
	dist[start] = cost;
	pq.push({ start, cost });

	// 큐가 빌 때까지
	while (!pq.empty()) {
		// 3. 최상위 노드 확인
		Edge now = pq.top();
		pq.pop();

		if (now.cost > dist[now.to])
			continue;

		// 4. next 찾기
		for (auto e : edges[now.to]) {
			int next = e.to;
			int w = e.cost;

			int nextcost = dist[now.to] + w;
			if (dist[next] <= nextcost)
				continue;

			// 5. next 등록
			dist[next] = nextcost;
			pq.push({ next, nextcost });
		}
	}

}

int main() {
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;

		edges[u].push_back({ v, w });
		edges[v].push_back({ u, w });
	}

	cin >> A >> B;

	// 1 -> A, 1 -> B
	dijkstra(1, 0);
	int oneA = dist[A];
	int oneB = dist[B];

	// A -> B, A -> N
	dijkstra(A, 0);
	int AB = dist[B];
	int AN = dist[N];

	dijkstra(B, 0);
	int BA = dist[A];
	int BN = dist[N];

	long long route1 = (long long)oneA + AB + BN; // 1 -> A -> B -> N
	long long route2 = (long long)oneB + BA + AN; // 1 -> B -> A -> N

	if (oneA >= INF || AB >= INF || BN >= INF) route1 = INF * 3LL;
	if (oneB >= INF || BA >= INF || AN >= INF) route2 = INF * 3LL;

	long long ans = min(route1, route2);

	if (ans >= INF * 3LL) cout << -1;
	else cout << ans;
}
