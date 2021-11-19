#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, int>> cluster;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void ModMap(vector<vector<char>>& map, cluster c) {

}

vector<pair<int, int>> CheckCluster(const vector<vector<char>>& map, vector<vector<bool>>& visited,
	int R, int C, int x, int y) {
	vector<pair<int, int>> cluster;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		visited[cx][cy] = true;
		cluster.push_back({ cx, cy });
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] != 'x') continue;

			q.push({ nx, ny });
		}
	}

	return cluster;
}

void CheckInAir(vector<vector<char>>& map, int R, int C, int h) {
	vector<vector<bool>> visited(R, vector<bool>(C, false));

	for (int i = 0; i < C; ++i) {
		if (map[R - 1][i] == 'x' and visited[R - 1][i] == false) {
			CheckCluster(map, visited, R, C, R - 1, i);
		}
	}

	vector<cluster> clusters;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[i][j] == 'x' and visited[i][j] == false) {
				cluster c = CheckCluster(map, visited, R, C, i, j);
				clusters.push_back(c);
			}
		}
	}
}

bool Throwing(vector<vector<char>>& map, int R, int C, int h, bool left) {
	if (left) {
		for (int i = 0; i < C; ++i) {
			if (map[h][i] == 'x') {
				map[h][i] = '.';
				return true;
			}
		}
	}
	else {
		for (int i = C - 1; i >= 0; --i) {
			if (map[h][i] == 'x') {
				map[h][i] = '.';
				return true;
			}
		}
	}
	return false;
}

void Solution() {
	//Input
	int R, C;
	cin >> R >> C;
	vector<vector<char>> map(R, vector<char>(C));

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> map[i][j];
		}
	}

	int N;
	cin >> N;
	vector<int> heights(N);
	for (int i = 0; i < N; ++i) {
		int h;
		cin >> h;
		h = R - h;
		heights[i] = h;
	}

	//Start
	bool left = false;
	for (int i = 0; i < N; ++i) {
		left = (left == false);
		if (!Throwing(map, R, C, heights[i], left)) continue;
		CheckInAir(map, R, C, heights[i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solution();

	return 0;
}