/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <cstring> //memset

using namespace std;

/* ���� */
#define MAX_N 1000001

/* ���� */
int N;
int memo[MAX_N];

/* �Լ� */
int dp(int num, int cnt) {
    if(num == 1) return memo[1] < cnt? memo[1] + 1 : cnt + 1;
    int& ret = memo[num];
    if(memo[num] != -1 && cnt > memo[num]) return memo[num];
    if(num%6 == 0) return ret = min(dp(num/3, cnt+1), min(dp(num/2, cnt+1), dp(num-1, cnt+1))) + 1;
    if(num%3 == 0) return ret = min(dp(num/3, cnt+1), dp(num-1, cnt+1)) + 1;
    if(num%2 == 0) return ret = min(dp(num/2, cnt+1), dp(num-1, cnt+1)) + 1;
    return ret = dp(num-1, cnt+1) + 1;
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> N;

    /* Ǯ�� */
    memset(memo, -1, sizeof(memo));

    /* ��� */
    cout << dp(N, 0) << '\n';
}