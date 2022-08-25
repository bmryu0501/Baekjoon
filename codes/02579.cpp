/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <algorithm> // reverse
#include <cstring> // memset

/* math.h
#define _USE_MATH_DEFINES // need this to use math defines
#include <math.h>
*/

using namespace std;

/* 조건 */
#define MAX_N 301

/* 변수 */
int N, tmp;
int score[MAX_N], memo[MAX_N];

/* 함수 */
int dp(int idx) {
    if (idx >= N) return 0;
    int& ret = memo[idx];
    if (ret != -1) return ret;
    return ret = max(score[idx] + dp(idx + 2), score[idx] + score[idx + 1] + dp(idx + 3));
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
        cin >> score[i];
    }

    /* 풀이 */
    score[N] = 0;
    memset(memo, -1, sizeof(memo));
    reverse(score, score + N);

    /* 출력 */
    cout << dp(0) << endl;
}