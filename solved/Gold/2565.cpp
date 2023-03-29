/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_LINE 101
#define MAX_POS 501 // max position. 전봇대의 위치의 최대 갯수

/* 변수 */
int N, arr[MAX_POS];
int dp[MAX_POS]; // 각 arr[i]에 대한 LIS의 길이
int max_LIS = 0; // LIS값

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;
    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        cin >> arr[tmp];
        dp[i] = 1; // dp를 1로 초기화
    }

    /* 풀이 */
    for(int i = 0; i < MAX_POS; i++) {
        if(arr[i] == 0) { // A[i]에 전선이 없는 경우
            dp[i] = 0;
            continue;
        }
        for(int j = 0; j < i; j++) { // dp[i]에 LIS 업데이트
            if(arr[j] < arr[i] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
                if(max_LIS < dp[i]) // max_LIS 업데이트
                    max_LIS = dp[i];
            }
        }
    }

    /* 출력 */
    cout << N - max_LIS << '\n';
}