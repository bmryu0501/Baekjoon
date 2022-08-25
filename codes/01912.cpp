/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_N 100001

/* 변수 */
int N, result;
int input[MAX_N];

/* 함수 */
int dp(int i) {
    if(i == 0) {
        return result = input[0];
    }

    int tmp = dp(i-1) + input[i];
    if(result < input[i]) result = input[i];
    if(tmp > 0) {
        if(result < tmp) result = tmp;
        return tmp;
    }
    else return 0;
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> input[i];

    /* 풀이 */
    dp(N-1);

    /* 출력 */
    cout << result << '\n';
}