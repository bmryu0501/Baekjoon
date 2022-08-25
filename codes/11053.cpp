/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_N 1001
#define MAX_A 1001

/* 변수 */
int N, arr[MAX_N], dp[MAX_N];
int result = 1; // 최댓값

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < MAX_N; i++)
        dp[i] = 1;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j] + 1;
                if(result < dp[i]) {
                    result = dp[i];
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}