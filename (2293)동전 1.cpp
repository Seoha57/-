/**************************************
���� 1
      �ð� ����          �޸� ����
0.5 �� (�߰� �ð� ����)      4 MB

����
n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���. 
�� ������ ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �� ����� ���� ���Ͻÿ�.
������ ������ �� ���� ����� �� �ִ�.
����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է�
ù° �ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����. 
������ ��ġ�� 100,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ����� ���� ����Ѵ�. ����� ���� 2^31���� �۴�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<int>& c, int n, int k, set<deque<int>>& cases, deque<int> bag, int total) {
	if (total == k) {
		sort(bag.begin(), bag.end());
		cases.insert(bag);
		return;
	}
	else if (total > k)
		return;

	for (int i = 0; i < n; ++i) {
		bag.push_back(c[i]);
		dfs(c, n, k, cases, bag, total + c[i]);
		bag.pop_back();
	}
}

int solution_dfs(const vector<int>& c, int n, int k) {
	set<deque<int>> cases;
	deque<int> bag;

	dfs(c, n, k, cases, bag, 0);

	return cases.size();
}

int solution(const vector<int>& c, int n, int k) {
	vector<long long> dp(k + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = c[i]; j <= k; ++j) {
			dp[j] += dp[j - c[i]];
		}
	}

	return dp[k];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}

	cout << solution(coins, n, k) << '\n';

	return 0;
}