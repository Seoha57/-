/**************************************
���ٲ���
�ð� ����   �޸� ����	
   2 ��       128 MB

����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�. 
�����̴� �Ȱų� �����̵��� �� �� �ִ�. ����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. 
�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.

�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
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
	//first - ������ Ƚ��, second - ������ ��ġ
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

		//�����̰� ������ġ�� �����ϸ� ����
		if (next == k) {
			ans = cnt;
			break;
		}
		else {
			cnt++;
			//1�� �Ŀ� X+1 �̵�
			int n = next + 1;
			if (n < max_pos) {
				if (dpTable[n] > cnt) {
					dpTable[n] = cnt;
					move.push({ cnt, n });
				}
			}
			//1�� �Ŀ� X-1 �̵�
			n = next - 1;
			if (n >= 0) {
				if (dpTable[n] > cnt) {
					dpTable[n] = cnt;
					move.push({ cnt, n });
				}
			}
			//1�� �Ŀ� 2*X �����̵�
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