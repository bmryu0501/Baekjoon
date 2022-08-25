/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <string>

using namespace std;

/* 조건 */
#define MAX_N 1001

/* 변수 */
string X, Y;
int dp[MAX_N][MAX_N];

/* 함수 */
void init() {
    for(int i = 0; i < MAX_N; i++)
        for(int j = 0; j < MAX_N; j++)
            dp[i][j] = -1;
}

int LCS(int i, int j) {
    if(i < 0 || j < 0) return 0;

    int& ret = dp[i][j];
    if(ret > -1) return ret;

    if(X[i] == Y[j])
        return ret = LCS(i-1, j-1) + 1;
    else return ret = max(LCS(i-1, j), LCS(i, j-1));
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> X;
    cin >> Y;

    /* 풀이 */
    init();

    cout << LCS(X.length() - 1, Y.length() - 1) << '\n';
}