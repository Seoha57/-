/**************************************
�� ��� - 9
�ð� ����   �޸� ����
   1 ��       128 MB

����
������ ���� ��Ģ�� ������ �ڿ� ���� ��� ������.

�Է�
ù° �ٿ� N(1 �� N �� 100)�� �־�����.

���
ù° �ٺ��� 2��N-1��° �ٱ��� ���ʴ�� ���� ����Ѵ�.

���� �Է�
5
���� ���
*********
 *******
  *****
   ***
    *
   ***
  *****
 *******
*********
**************************************/

#include <bits/stdc++.h>

using namespace std;

void solution(int n) {
    int total_star = 2 * (n - 1) + 1;
    int total_temp = 2 * (n - 1) + 1;
    int blank = 0;
    for (int i = 0; i < n; ++i) {
        int empty = blank;
        while (empty > 0) {
            cout << ' ';
            --empty;
        }
        for (int j = 0; j < total_star; ++j) {
            cout << '*';
        }
        if (total_star > 1) {
            blank += 1;
            total_star -= 2;
        }
        cout << '\n';
    }
    blank -= 1;
    total_star += 2;
    for (int i = n; i < total_temp; ++i) {
        int empty = blank;
        while (empty > 0) {
            cout << ' ';
            --empty;
        }
        for (int j = 0; j < total_star; ++j) {
            cout << '*';
        }
        blank -= 1;
        total_star += 2;
        cout << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    solution(n);

    return 0;
}