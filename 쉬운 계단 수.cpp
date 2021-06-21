/**************************************
쉬운 계단 수
시간 제한   메모리 제한
   1 초        256 MB

문제
45656이란 수를 보자.
이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
**************************************/

#include<bits/stdc++.h>

using namespace std;

int share = 1000000000;

/*DP(Bottom-Up)*/
long long solution(int n) {
	vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));

	for (int i = 1; i < 10; ++i) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j + 1] % share + dp[i - 1][j - 1] % share;

			dp[i][j] %= share;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans += dp[n][i];
	}
	return ans % share;
}

/*DP(Top-Down)*/
long long dfs(int length, int n, int last, vector<vector<long long>>& table) {

	if (length == n)
		return 1;

	long long count = 0;

	if (table[last][n - length + 1] != -1)
		return table[last][n - length + 1];

	if (last + 1 <= 9)
		count += dfs(length + 1, n, last + 1, table) % 1000000000;
	if (last - 1 >= 0)
		count += dfs(length + 1, n, last - 1, table) % 1000000000;

	table[last][n - length + 1] = count % 1000000000;

	return count;
}

int solution_top_down(int n) {

	long long answer = 0;
	vector<vector<long long>> table(10, vector<long long>(101, -1));

	for (int j = 1; j <= 9; ++j) {
		if (table[j][n] != -1)
			answer += table[j][n] % 1000000000;
		else
			answer += dfs(1, n, j, table) % 1000000000;
	}

	return answer % 1000000000;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << solution(n) << '\n';

	return 0;
}