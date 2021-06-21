/**************************************
���� ��� ��
�ð� ����   �޸� ����
   1 ��        256 MB

����
45656�̶� ���� ����.
�� ���� ������ ��� �ڸ����� ���̰� 1�� ����. �̷� ���� ��� ����� �Ѵ�.
�����̴� ���� ���̰� N�� ��� ���� �� �� �ִ��� �ñ�������.
N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (0���� �����ϴ� ���� ����.)

�Է�
ù° �ٿ� N�� �־�����. N�� 1���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ������ 1,000,000,000���� ���� �������� ����Ѵ�.
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