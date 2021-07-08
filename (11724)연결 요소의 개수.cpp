/**************************************
���� ����� ���� ����
�ð� ����    �޸� ����
   3 ��        512 MB

����
���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. (1 �� N �� 1,000, 0 �� M �� N��(N-1)/2) 
��° �ٺ��� M���� �ٿ� ������ �� ���� u�� v�� �־�����. (1 �� u, v �� N, u �� v) 
���� ������ �� ���� �־�����.

���
ù° �ٿ� ���� ����� ������ ����Ѵ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

int FindParent(const vector<int>& p, int x) {
	if (x == p[x]) return x;
	return FindParent(p, p[x]);
}

void UnionParent(vector<int>& p, int a, int b) {
	a = FindParent(p, a);
	b = FindParent(p, b);
	if (a < b) p[b] = a;
	else p[a] = b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i)
		p[i] = i;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		if(FindParent(p, u) != FindParent(p, v))
			UnionParent(p, u, v);
	}

	for (int i = 1; i <= n; ++i) {
		int p_i = p[i];
		if (p[i] != p[p_i]) {
			p[i] = p[p_i];
		}
	}

	set<int> p_set;
	int c = 0;
	for (int i = 1; i <= n; ++i) {
		if (c != p[i]) {
			c = p[i];
			p_set.insert(c);
		}
	}
	
	cout << p_set.size() << '\n';

	return 0;
}