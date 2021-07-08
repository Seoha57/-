/**************************************
연결 요소의 개수 성공
시간 제한    메모리 제한
   3 초        512 MB

문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 
같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.
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