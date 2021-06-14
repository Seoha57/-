/**************************************
������ȣ���̱�
�ð� ����	�޸� ����	
   1 ��        128 MB

����
<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. 
ö���� �� ������ ������ ����� ���� ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�. 
���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. 
�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�. 
������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�,
�� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.
**************************************/
#include <bits/stdc++.h>

using namespace std;

bool dfs(const vector<string>& map, vector<vector<bool>>& visited, int x, int y, int& sum) {
	if (x < 0 or y < 0 or x >= map.size() or y >= map.size())
		return false;

	if (!visited[x][y] and map[x][y] == '1') {
		visited[x][y] = true;
		sum += 1;

		dfs(map, visited, x + 1, y, sum);
		dfs(map, visited, x - 1, y, sum);
		dfs(map, visited, x, y + 1, sum);
		dfs(map, visited, x, y - 1, sum);

		return true;
	}

	return false;
}

void solution(int n, const vector<string>& str) {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<int> estates;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (str[i][j] == '1' and !visited[i][j]) {
				int sum = 0;
				if (dfs(str, visited, i, j, sum)) {
					estates.push_back(sum);
				}
			}
		}
	}

	sort(estates.begin(), estates.end());

	cout << estates.size() << '\n';
	for (auto house : estates) {
		cout << house << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<string> str(N);
	for (int i = 0; i < N; ++i) {
		cin >> str[i];
	}

	solution(N, str);

	return 0;
}