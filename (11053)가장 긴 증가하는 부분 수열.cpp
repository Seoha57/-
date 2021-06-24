/**************************************
���� �� �����ϴ� �κ� ����
�ð� ����   �޸� ����
   1 ��       256 MB

����
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

int solution(const vector<int>& nums, int n) {
	vector<int> inc(n, 1);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[i] > nums[j] and inc[i] < inc[j] + 1)
				inc[i] = inc[j] + 1;
		}
	}

	return *max_element(inc.begin(), inc.end());
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