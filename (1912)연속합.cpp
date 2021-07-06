/**************************************
������
    �ð� ����          �޸� ����	
1 �� (�߰� �ð� ����)     128 MB

����
n���� ������ �̷���� ������ ������ �־�����. �츮�� �� �� ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�.
��, ���� �� �� �̻� �����ؾ� �Ѵ�.
���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 �̶�� ������ �־����ٰ� ����. 
���⼭ ������ 12+21�� 33�� ������ �ȴ�.

�Է�
ù° �ٿ� ���� n(1 �� n �� 100,000)�� �־����� ��° �ٿ��� n���� ������ �̷���� ������ �־�����. 
���� -1,000���� ũ�ų� ����, 1,000���� �۰ų� ���� �����̴�.

���
ù° �ٿ� ���� ����Ѵ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

int solution(const vector<int>& nums, int n) {
	vector<int> dp(n);

	dp[0] = nums[0];
	int ans = nums[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = max(nums[i], nums[i] + dp[i - 1]);
		ans = max(dp[i], ans);
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	cout << solution(nums, n) << '\n';

	return 0;
}