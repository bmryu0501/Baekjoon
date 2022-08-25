/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_N 10001

/* 변수 */
int lhs, rhs;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */

    /* 풀이 */
    while(1) {
        cin >> lhs >> rhs;
        if(lhs == 0 && rhs == 0) break;
        if(rhs % lhs == 0) {
            cout << "factor\n";
            continue;
        } else if(lhs % rhs == 0) {
            cout << "multiple\n";
            continue;
        } else cout << "neither\n";
    }

    /* 출력 */
}