/**************************************
���� 0
�ð� ����  �޸� ����
   1 ��       256 MB

����
�ر԰� ������ �ִ� ������ �� N�����̰�, ������ ������ �ſ� ���� ������ �ִ�.

������ ������ ����ؼ� �� ��ġ�� ���� K�� ������� �Ѵ�. �̶� �ʿ��� ���� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N �� 10, 1 �� K �� 100,000,000)

��° �ٺ��� N���� �ٿ� ������ ��ġ Ai�� ������������ �־�����. (1 �� Ai �� 1,000,000, A1 = 1, i �� 2�� ��쿡 Ai�� Ai-1�� ���)

���
ù° �ٿ� K���� ����µ� �ʿ��� ���� ������ �ּڰ��� ����Ѵ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

int solution(const vector<int>& c, int n, int k) {
	//vector<int> dp(k + 1, 1e9);
	int cnt = 0;
	int index = n - 1;
	while (k > 0) {
		if (k < c[index]) {
			--index;
			continue;
		}
		k -= c[index];
		cnt++;
	}
	return cnt;
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