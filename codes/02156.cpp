/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <cstring> // memset

using namespace std;

/* ���� */
#define MAX_N 10001

/* ���� */
int N;
int wine[MAX_N], memo[MAX_N];

/* �Լ� */
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

    /* �Է� */
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> wine[i];
    }

    /* Ǯ�� */
    memset(memo, -1, sizeof(memo));

    /* ��� */
    cout << dp(N-1) << '\n';
}