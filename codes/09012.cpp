/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* 조건 */
#define MAX_LENGTH 50

/* 변수 */
int T;
string str;

/* 함수 */
string isVPS(string str) {
    int lb = 0; // left bracket
    int rb = 0; // right bracket
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') lb++;
        else {
            if(lb == rb) return "NO";
            rb++;
        }
    }
    if(lb == rb) return "YES";
    else return "NO";
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> T;

    /* 풀이 */
    for(int i = 0; i < T; i++) {
        cin >> str;
        cout << isVPS(str) << '\n';
    }
}