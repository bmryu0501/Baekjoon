/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_N 101
#define MAX_K 100001
#define MAX_W 100001
#define MAX_V 1001

/* 변수 */
int N, K;
int W[MAX_N], V[MAX_N];
int memo[MAX_N][MAX_K];

/* 함수 */
int dp(int n, int k) {
    if(n == 0 || k <= 0) {
        if(k >= W[n]) return V[n];
        return 0;
    }

    int& ret = memo[n][k];
    if(ret > -1) return ret;
    if(k < W[n]) return ret = dp(n-1, k);
    return ret = max(dp(n-1, k-W[n]) + V[n], dp(n-1, k));
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
    }

    /* 풀이 및 출력 */
    for(int i = 0; i < MAX_N; i++) {
        for(int j = 0; j < MAX_K; j++)
            memo[i][j] = -1;
    }
    cout << dp(N-1, K) << '\n';
}