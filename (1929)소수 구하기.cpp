/**************************************
�Ҽ� ���ϱ�
�ð� ����   �޸� ����
   2 ��       256 MB

����
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000) M�̻� N������ �Ҽ��� �ϳ� �̻� �ִ� �Է¸� �־�����.

���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

void print(const vector<bool>& nums, int n, int m) {
	for (int i = n; i <= m; ++i) {
		if (!nums[i])
			cout << i << '\n';
	}
}

void solution(int n, int m) {
	vector<bool> nums(m + 1, false);
	nums[1] = true;
	for (int i = 2; i <= m; ++i) {
		if (nums[i]) continue;
		for (int j = i + i; j <= m; j += i) {
			nums[j] = true;
		}
	}

	print(nums, n, m);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	solution(n, m);

	return 0;
}