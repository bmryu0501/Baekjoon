/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <stack>

using namespace std;

/* 조건 */
#define MAX_K 100000

/* 변수 */
int K, tmp, result = 0;
stack<int> s;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> K;

    /* 풀이 */
    for(int i = 0; i < K; i++) {
        cin >> tmp;
        if(tmp == 0) s.pop();
        else s.push(tmp);
    }

    /* 출력 */
    for(int i = s.size(); i > 0; i--) {
        result += s.top();
        s.pop();
    }
    cout << result << '\n';
}