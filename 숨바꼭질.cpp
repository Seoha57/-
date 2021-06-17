/**************************************
숨바꼭질
시간 제한   메모리 제한	
   2 초       128 MB

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
**************************************/
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int max_pos = 100001;

struct cmp {
	bool operator()(pi& a, pi& b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}
};

int solution(int n, int k) {
	int ans = 0;
	if (n == k) return ans;

	vector<int> dpTable(max_pos, max_pos);
	//first - 움직인 횟수, second - 도착한 위치
	priority_queue<pi, vector<pi>, cmp> move;
	move.push({ 1, n + 1 });
	if (n != 0)
		move.push({ 1, n - 1 });
	if ((n * 2) < max_pos)
		move.push({ 1, n * 2 });

	while (!move.empty()) {
		int cnt = move.top().first;
		int next = move.top().second;
		move.pop();

		//수빈이가 동생위치에 도착하면 종료
		if (next == k) {
			ans = cnt;
			break;
		}
		else {
			cnt++;
			//1초 후에 X+1 이동
			int n = next + 1;
			if (n < max_pos) {
				if (dpTable[n] > cnt) {
					dpTable[n] = cnt;
					move.push({ cnt, n });
				}
			}
			//1초 후에 X-1 이동
			n = next - 1;
			if (n >= 0) {
				if (dpTable[n] > cnt) {
					dpTable[n] = cnt;
					move.push({ cnt, n });
				}
			}
			//1초 후에 2*X 순간이동
			n = next * 2;
			if (n < max_pos) {
				if (dpTable[n] > cnt) {
					dpTable[n] = cnt;
					move.push({ cnt, n });
				}
			}
		}
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	cout << solution(n, k) << '\n';

	return 0;
}