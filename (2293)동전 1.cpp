/**************************************
동전 1
      시간 제한          메모리 제한
0.5 초 (추가 시간 없음)      4 MB

문제
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 
이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오.
각각의 동전은 몇 개라도 사용할 수 있다.
사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 
동전의 가치는 100,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 경우의 수를 출력한다. 경우의 수는 2^31보다 작다.
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