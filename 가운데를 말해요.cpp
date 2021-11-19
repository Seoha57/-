#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int> max_q;
	priority_queue<int, vector<int>, greater<int>> min_q;
	for(int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (max_q.size() - min_q.size() == 0) 
			max_q.push(num);
		else
			min_q.push(num);

		if (!max_q.empty() && !min_q.empty() && max_q.top() > min_q.top()) {
			int max_value = max_q.top();
			int min_value = min_q.top();
			max_q.pop();
			min_q.pop();
			max_q.push(min_value);
			min_q.push(max_value);
		}
		cout << max_q.top() << '\n';
	}

	return 0;
}