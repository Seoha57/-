/**************************************
ȸ�ǽ� ����
�ð� ����   �޸� ����
   2 ��        128 MB

����
�� ���� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǿ� ���Ͽ� ȸ�ǽ� ���ǥ�� ������� �Ѵ�. 
�� ȸ�� I�� ���� ���۽ð��� ������ �ð��� �־��� �ְ�, �� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� 
ȸ���� �ִ� ������ ã�ƺ���. 
��, ȸ�Ǵ� �ѹ� �����ϸ� �߰��� �ߴܵ� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�. 
ȸ���� ���۽ð��� ������ �ð��� ���� ���� �ִ�. �� ��쿡�� �������ڸ��� ������ ������ �����ϸ� �ȴ�.

�Է�
ù° �ٿ� ȸ���� �� N(1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N+1 �ٱ��� �� ȸ���� ������ �־����µ� 
�̰��� ������ ���̿� �ΰ� ȸ���� ���۽ð��� ������ �ð��� �־�����. 
���� �ð��� ������ �ð��� 231-1���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٿ� �ִ� ����� �� �ִ� ȸ���� �ִ� ������ ����Ѵ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PInt;

bool compare(PInt a, PInt b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int solution(vector<PInt> t) {
	int now = t[0].second;
	int cnt = 1;

	for (int i = 1; i < t.size(); ++i) {
		if (now <= t[i].first) {
			cnt++;
			now = t[i].second;
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<PInt> t(n);

	for (int i = 0; i < n; ++i) {
		cin >> t[i].first >> t[i].second;
	}

	sort(t.begin(), t.end(), compare);

	cout << solution(t) << '\n';

	return 0;
}