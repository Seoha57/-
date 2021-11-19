#include <bits/stdc++.h>

using namespace std;

#define magic 1000000007


/************
11! = 39,916,800        % 1000000007 = 39,916,800
12! = 479,001,600       % 1000000007 = 479,001,600
13! = 6,227,020,800     % 1000000007 = 227,020,758
14! = 87,178,291,200    % 1000000007 = 178,290,591
15! = 1,307,674,368,000 % 1000000007 = 674,358,851

15 1           = 15

 15!
-----
1!*14!         = 3

14 1            = 14

 14!
-----
1!*13!         = 0
************/

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<long long> dp(N + 1);
	dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] = ((dp[i - 1] % magic) * (i % magic)) % magic;
	}

	long long NF = dp[N];
	long long KF = dp[K];
	long long NK = dp[N - K];

	long long answer = NF / (KF * NK);
	cout << answer << "\n";

	return 0;
}