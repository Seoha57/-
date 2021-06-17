/**************************************
���� �ﰢ�� 
�ð� ����  �޸� ����	
   2 ��      128 MB	

����
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
�� �׸��� ũ�Ⱑ 5�� ���� �ﰢ���� �� ����̴�.

�� ���� 7���� �����ؼ� �Ʒ��� �ִ� �� �� �ϳ��� �����Ͽ� �Ʒ������� ������ ��, 
�������� ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��϶�. 
�Ʒ����� �ִ� ���� ���� ������ ���õ� ���� �밢�� ���� �Ǵ� �밢�� �����ʿ� �ִ� �� �߿����� ������ �� �ִ�.

�ﰢ���� ũ��� 1 �̻� 500 �����̴�. �ﰢ���� �̷�� �ִ� �� ���� ��� �����̸�, ������ 0 �̻� 9999 �����̴�.

�Է�
ù° �ٿ� �ﰢ���� ũ�� n(1 �� n �� 500)�� �־�����, ��° �ٺ��� n+1��° �ٱ��� ���� �ﰢ���� �־�����.

���
ù° �ٿ� ���� �ִ밡 �Ǵ� ��ο� �ִ� ���� ���� ����Ѵ�.
**************************************/

#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>>& tri) {
    n -= 2;
    while (n >= 0) {
        for (int i = 0; i < tri[n].size(); ++i) {
            tri[n][i] += max(tri[n + 1][i], tri[n + 1][i + 1]);
        }
        --n;
    }

    return tri[0][0];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> triangle;
    for (int i = 0; i < n; ++i) {
        vector<int> t;
        for (int j = 0; j <= i; ++j) {
            int x;
            cin >> x;
            t.push_back(x);
        }
        triangle.push_back(t);
    }

    cout << solution(n, triangle) << '\n';

    return 0;
}