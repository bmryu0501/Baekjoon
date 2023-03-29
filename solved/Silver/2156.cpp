/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <cstring> // memset

using namespace std;

/* 조건 */
#define MAX_N 10001

/* 변수 */
int N;
int wine[MAX_N], memo[MAX_N];

/* 함수 */
int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

int dp(int idx) {
    if(idx < 0) return 0;
    int& ret = memo[idx];
    if(ret > -1) return ret;
    return ret = max3(dp(idx-1), wine[idx] + dp(idx-2), wine[idx] + wine[idx-1] + dp(idx-3));
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> wine[i];
    }

    /* 풀이 */
    memset(memo, -1, sizeof(memo));

    /* 출력 */
    cout << dp(N-1) << '\n';
}