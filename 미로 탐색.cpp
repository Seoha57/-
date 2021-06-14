/**************************************
미로
시간 제한   메모리 제한	
   1 초       192 MB	

문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.이러한 미로가 주어졌을 때, 
(1, 1)에서 출발하여(N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야(N, M)의 위치로 이동할 수 있다.칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.다음 N개의 줄에는 M개의 정수로 미로가 주어진다.
각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다.항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
**************************************/
#include <bits/stdc++.h>

#define LARGE 1000000
using namespace std;

class Space {
public:
	int x, y, cost;
	Space(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
};

bool operator<(const Space& a, const Space& b) {
	return a.cost > b.cost;
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int search(int n, int m, const vector<vector<int>>& map) {
	vector<vector<int>> cost_table(n, vector<int>(m, LARGE));

	Space s(0, 0, map[0][0]);
	priority_queue<Space> q;
	q.push(s);

	while (!q.empty()) {
		Space t = q.top();
		q.pop();

		if (cost_table[t.x][t.y] < t.cost) continue;

		for (int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];

			if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
			if (map[nx][ny] == 0) continue;

			int nCost = t.cost + map[nx][ny];
			if (nCost < cost_table[nx][ny]) {
				cost_table[nx][ny] = nCost;
				Space next(nx, ny, nCost);
				q.push(next);
			}
		}
 	}

	return cost_table[n - 1][m - 1];
}

int solution(int n, int m, const vector<string>& str) {
	vector<vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			map[i][j] = str[i][j] - '0';
		}
	}

	return search(n, m, map);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> str(N);

	for (int i = 0; i < N; ++i) {
		cin >> str[i];
	}

	cout << solution(N, M, str) << '\n';

	return 0;
}
