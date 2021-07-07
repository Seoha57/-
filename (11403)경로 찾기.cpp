/**************************************
��� ã��
�ð� ����  �޸� ����
   1 ��       256 MB

����
����ġ ���� ���� �׷��� G�� �־����� ��, ��� ���� (i, j)�� ���ؼ�, i���� j�� ���� ��ΰ� �ִ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٺ��� N�� �ٿ��� �׷����� ���� ����� �־�����. 
i��° ���� j��° ���ڰ� 1�� ��쿡�� i���� j�� ���� ������ �����Ѵٴ� ���̰�, 0�� ���� ���ٴ� ���̴�. 
i��° ���� i��° ���ڴ� �׻� 0�̴�.

���
�� N���� �ٿ� ���ļ� ������ ������ ������� �������� ����Ѵ�. 
���� i���� j�� ���� ��ΰ� ������ i��° ���� j��° ���ڸ� 1��, ������ 0���� ����ؾ� �Ѵ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

int BigInt = 1e5;

void printMap(const vector<vector<int>>& m, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] == BigInt)
				cout << '0' << " ";
			else
				cout << '1' << " ";
		}
		cout << '\n';
	}

}

void solution(vector<vector<int>>& map, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}

	printMap(map, n);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				map[i][j] = BigInt;
		}
	}

	solution(map, n);

	return 0;
}