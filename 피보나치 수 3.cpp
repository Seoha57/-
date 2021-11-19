#include <bits/stdc++.h>

using namespace std;

#define share 1000000
#define len 100

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<long long> fib(len);
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fib[i % len] = ((fib[(i - 1) % len] % share) + (fib[(i - 2) % len] % share)) % share;
	}
	cout << fib[n % len] << "\n";

	return 0;
}