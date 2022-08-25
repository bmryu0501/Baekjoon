/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <vector>

using namespace std;

/* 조건 */
#define DIVISOR 1000000000
#define MAX_N 101

/* 변수 */
int N, arr[MAX_N][10];
int result = 0;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;

    /* 풀이 */
    for(int i = 0; i < 10; i++) {
        arr[1][i] = 1;
    }

    for(int i = 2; i <= N; i++) {
        arr[i][0] = arr[i-1][1]%DIVISOR;
        for(int j = 1; j < 9; j++) {
            arr[i][j] = (arr[i-1][j-1]%DIVISOR) + (arr[i-1][j+1]%DIVISOR);
        }
        arr[i][9] = arr[i-1][8]%DIVISOR;
    }

    for(int i = 1; i < 10; i++) {
        result += arr[N][i]%DIVISOR;
        result %= DIVISOR;
    }

    /* 출력 */
    cout << result << '\n';
}