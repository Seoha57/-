/**************************************
DFS�� BFS
�ð� ����  �޸� ����
   2 ��       128 MB

����
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. 
���� ��ȣ�� 1������ N�������̴�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. 
���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. � �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. 
�Է����� �־����� ������ ������̴�.

���
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. V���� �湮�� ���� ������� ����ϸ� �ȴ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

void bfs(int n, int v, const vector<vector<int>>& map) {
	vector<bool> visited(n + 1, false);
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int c = q.front();
		q.pop();
		cout << c << " ";

		for (int i = 1; i <= n; ++i) {
			if (map[c][i] != 0 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void helper(const vector<vector<int>>& map, vector<bool>& visited, int n, int v) {
	cout << v << " ";

	for (int i = 1; i <= n; ++i) {
		if (map[v][i] != 0 && !visited[i]) {
			visited[i] = true;
			helper(map, visited, n, i);
		}
	}
}

void dfs(int n, int v, const vector<vector<int>>& map) {
	vector<bool> visited(n + 1, false);
	visited[v] = true;
	helper(map, visited, n, v);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	dfs(n, v, map);
	cout << '\n';
	bfs(n, v, map);

	return 0;
}