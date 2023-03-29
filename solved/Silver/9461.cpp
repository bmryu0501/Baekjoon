/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAXINPUT 101

/* 변수 */
long T, N;
long memo[MAXINPUT] = {0, };

/* 함수 */
long P(long n) {
    if(memo[n] == 0)
        memo[n] = P(n-5) + P(n-1);
    return memo[n];
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 초기화 */
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 1;
    memo[4] = 2;
    memo[5] = 2;

    /* 입력 및 풀이 */
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        cout << P(N) << '\n';
    }
}