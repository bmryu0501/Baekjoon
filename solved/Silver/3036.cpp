/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_N 100

/* 변수 */
int N, gcd;
int arr[MAX_N+1];

/* 함수 */
int GCD(int a, int b) {
    if(a % b == 0) return b;
    return GCD(b, a%b);
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
        cin >> arr[i];
    }

    /* 풀이 */
    for(int i = 1; i < N; i++) {
        gcd = GCD(arr[0], arr[i]);
        cout << arr[0]/gcd << '/' << arr[i]/gcd << '\n';
    }
}