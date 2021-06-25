/**************************************
별 찍기 - 9
시간 제한   메모리 제한
   1 초       128 MB

문제
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

예제 입력
5
예제 출력
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