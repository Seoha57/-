/**************************************
LCS
�ð� ����   �޸� ����
   1 ��       256 MB

����
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.
���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

�Է�
ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.

���
ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�.
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