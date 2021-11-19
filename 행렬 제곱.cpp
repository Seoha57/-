#include <bits/stdc++.h>

using namespace std;

#define MOD 1000

typedef vector<vector<int>> MAT;

MAT MatMultiply(const MAT& a, const MAT& b) {
	MAT mat(a.size(), vector<int>(a.size()));

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			for (int k = 0; k < a.size(); ++k) {
				mat[i][j] += (a[i][k] % MOD * b[k][j] % MOD);
			}
			mat[i][j] %= MOD;
		}
	}
	return mat;
}

void PrintMat(const MAT& mat) {
	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat.size(); ++j) {
			cout << mat[i][j] % MOD << " ";
		}
		cout << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, b;
	cin >> n >> b;

	MAT matrix_init(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix_init[i][j];
		}
	}
	/****************
	a^5
	a^4 * a
	a^2 * a^2 * a

	3
	2 * 1

	10
	5 * 2
	(4 * 1) * 2
	2 * 2 * 1 * 2 
	*****************/
	MAT matrix(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		matrix[i][i] = 1;
	}
	MAT mat_temp = matrix_init;
	while (b > 0) {
		if (b % 2 == 1) {
			matrix = MatMultiply(matrix, mat_temp);
		}
		b /= 2;
		mat_temp = MatMultiply(mat_temp, mat_temp);
	}
	
	/*while (b > 1) {
		vector<vector<int>> matrix_temp(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					matrix_temp[i][j] += (matrix[i][k] % MOD * matrix_init[k][j] % MOD);
				}
				matrix[i][j] %= MOD;
			}
		}
		matrix = matrix_temp;
		--b;
	}*/
	PrintMat(matrix);

	return 0;
}