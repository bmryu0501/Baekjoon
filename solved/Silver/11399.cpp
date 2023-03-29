/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

/* 조건 */
#define MAX_N 1001

/* 변수 */
int N;
int arr[MAX_N];
int sum = 0;

/* 함수 */

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
    sort(arr, arr+N);
    for(int i = 0; i < N; i++) {
        sum += arr[i];
        arr[i+1] += arr[i];
    }

    /* 출력 */
    cout << sum << '\n';
}