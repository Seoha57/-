/**************************************
�ִܰ��
�ð� ����    �޸� ����
   1 ��         256 MB

����
����׷����� �־����� �־��� ���������� �ٸ� ��� ���������� �ִ� ��θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, ��� ������ ����ġ�� 10 ������ �ڿ����̴�.

�Է�
ù° �ٿ� ������ ���� V�� ������ ���� E�� �־�����. (1��V��20,000, 1��E��300,000) ��� �������� 1���� V���� ��ȣ�� �Ű��� �ִٰ� �����Ѵ�. 
��° �ٿ��� ���� ������ ��ȣ K(1��K��V)�� �־�����. ��° �ٺ��� E���� �ٿ� ���� �� ������ ��Ÿ���� �� ���� ���� (u, v, w)�� ������� �־�����. 
�̴� u���� v�� ���� ����ġ w�� ������ �����Ѵٴ� ���̴�. u�� v�� ���� �ٸ��� w�� 10 ������ �ڿ����̴�. 
���� �ٸ� �� ���� ���̿� ���� ���� ������ ������ ���� ������ �����Ѵ�.

���
ù° �ٺ��� V���� �ٿ� ����, i��° �ٿ� i�� ���������� �ִ� ����� ��ΰ��� ����Ѵ�. 
������ �ڽ��� 0���� ����ϰ�, ��ΰ� �������� �ʴ� ��쿡�� INF�� ����ϸ� �ȴ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

constexpr auto largeInt = 1e9;

/*************���� ��ü�� �̿�****************/
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

/*************���� ����� �̿�****************/
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