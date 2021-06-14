/**************************************
�̷�
�ð� ����	�޸� ����	
   1 ��        192 MB	

����
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����.�̷��� �̷ΰ� �־����� ��, 
(1, 1)���� ����Ͽ�(N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.

���� �������� 15ĭ�� ������(N, M)�� ��ġ�� �̵��� �� �ִ�.ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

�Է�
ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����.���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����.
������ ������ �پ �Է����� �־�����.

���
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�.�׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.
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