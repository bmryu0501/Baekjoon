/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAXINPUT 1000001
const int devisor = 15746;

/* 변수 */
int N;
int arr[MAXINPUT] = {0, };

/* 함수 */
int func(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    if(arr[n] == 0) {
        arr[n] = (func(n - 1) + func(n - 2)) % devisor;
    }
    return arr[n] % devisor;
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;

    /* 풀이 */
    cout << func(N);
}