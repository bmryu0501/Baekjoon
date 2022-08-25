/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
using namespace std;

/* 조건 */
#define MAX_N 30
#define MAX_M 30

/* 변수 */
int T, N, M;
int C[MAX_N+1][MAX_M+1];


/* 함수 */
int combination(int n, int k) {
    if(C[n][k] > 0) return C[n][k];
    if(C[n][n-k] > 0) return C[n][k] = C[n][n-k];
    if(n == 0) return C[n][k] = 0;
    if(n == k) return C[n][k] = 1;
    if(k == 0) return C[n][k] = 1;
    return C[n][k] = combination(n-1, k-1) + combination(n-1, k);
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> T;

    /* 풀이 */
    for(int i = 0; i < T; i++) {
        cin >> N >> M;
        cout << combination(M, N) << '\n';
    }

    /* 출력 */
}