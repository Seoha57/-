/**************************************
LCS
시간 제한   메모리 제한
   1 초       256 MB

문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
**************************************/

#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2) {
	int m = s1.length();
	int n = s2.length();

	vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s1[i - 1] == s2[j - 1])
				t[i][j] = t[i - 1][j - 1] + 1;
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}

	return t[m][n];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;

	cin >> s1 >> s2;

	cout << lcs(s1, s2) << '\n';

	return 0;
}