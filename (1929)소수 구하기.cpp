/**************************************
소수 구하기
시간 제한   메모리 제한
   2 초       256 MB

문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
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