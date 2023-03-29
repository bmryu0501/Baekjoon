/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <stack>

using namespace std;

/* 조건 */
#define MAX_N 1000000
#define MAX_A 1000000

/* 변수 */
int N;
int arr[MAX_N];
stack<int> s;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;

    /* 풀이 */
    for(int i = 0, input, tmp; i < N; i++) {
        cin >> input;
        arr[i] = input;

        if(s.empty() || arr[s.top()] >= input) {
            s.push(i);
        } else {
            while(!s.empty() && arr[s.top()] < input) {
                arr[s.top()] = input;
                s.pop();
            }
            s.push(i);
        }
    }

    while(!s.empty()) {
        arr[s.top()] = -1;
        s.pop();
    }

    /* 출력 */
    for(int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}