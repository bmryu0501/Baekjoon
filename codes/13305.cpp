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
int N, arr_distance[MAX_N], arr_price[MAX_N];
long long result = 0;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        cin >> arr_distance[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> arr_price[i];
    }

    /* 풀이 */
    for(int i = 1, low = 0; i < N; i++) {
        if(arr_price[low] > arr_price[i]) { // 가격이 더 싼게 나오면
            result += (long long)arr_price[low] * (long long)arr_distance[i-1];
            low = i;
        } else {
            result += (long long)arr_price[low] * (long long)arr_distance[i-1];
        }
    }

    /* 출력 */
    cout << result << '\n';
}