/**************************************
최단경로
시간 제한    메모리 제한
   1 초         256 MB

문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 
단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1≤V≤20,000, 1≤E≤300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 
둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 
이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 
서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 
시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
**************************************/

#include <bits/stdc++.h>

using namespace std;

constexpr auto largeInt = 1e9;

/*************간선 자체를 이용****************/
void ShortestPath(int v, int e, int k, const vector<pair<int, int>>* edges) {
	vector<int> cost(v + 1, largeInt);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, k });
	cost[k] = 0;

	while (!pq.empty()) {
		int c = -pq.top().first;
		int p = pq.top().second;
		pq.pop();

		if (cost[p] < c) continue;

		for (int i = 0; i < edges[p].size(); ++i) {
			int next = edges[p][i].first;
			int nCost = edges[p][i].second + c;
			if (nCost < cost[next]) {
				cost[next] = nCost;
				if(edges[next].size() != 0)
					pq.push({ -nCost, next });
			}
		}
	}

	for (int i = 1; i <= v; ++i) {
		if (cost[i] == largeInt)
			cout << "INF" << '\n';
		else
			cout << cost[i] << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	cin >> v >> e >> k;

	vector<pair<int, int>> edges[20001];
	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({ v, w });
	}

	ShortestPath(v, e, k, edges);

	return 0;
}

/*************맵을 만들어 이용****************/
/*void ShortesPath(int v, int e, int k, const vector<vector<int>>& map) {
	vector<int> cost(v + 1, largeInt);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, k });
	cost[k] = 0;

	while (!pq.empty()) {
		int c = pq.top().first;
		int p = pq.top().second;
		pq.pop();

		if (cost[p] < c) continue;

		for (int i = 1; i <= v; ++i) {
			int next = map[p][i];
			if (next != 0 and c + next < cost[i]) {
				cost[i] = c + next;
				pq.push({ c + next, i });
			}
		}
	}

	for (int i = 1; i <= v; ++i) {
		if (cost[i] == largeInt)
			cout << "INF" << '\n';
		else
			cout << cost[i] << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	cin >> v >> e >> k;

	vector<vector<int>> map(v + 1, vector<int>(v + 1, 0));
	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		map[u][v] = w;
	}

	ShortesPath(v, e, k, map);

	return 0;
}*/