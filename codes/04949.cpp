/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* 조건 */

/* 변수 */
string str;
stack<char> s;
bool flag;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    do {
        /* 입력 */
        getline(cin, str, '\n');

        //cout << "\"" << str << "\" : ";

        if(str.length() == 1 && str[0] == '.') break;

        while(!s.empty()) s.pop();

        /* 풀이 */
        flag = true;

        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') s.push(str[i]);
            else if(str[i] == '{') s.push(str[i]);
            else if(str[i] == '[') s.push(str[i]);

            else if(str[i] == ')') {
                if(s.empty() || !(s.top() == '(')) {
                    flag = false;
                    break;
                } else {
                    s.pop();
                }
            } else if(str[i] == '}') {
                if(s.empty() || !(s.top() == '{')) {
                    flag = false;
                    break;
                } else {
                    s.pop();
                }
            } else if(str[i] == ']') {
                if(s.empty() || !(s.top() == '[')) {
                    flag = false;
                    break;
                } else {
                    s.pop();
                }
            }
        }

        if(!s.empty()) flag = false;

        if(flag) cout << "yes\n";
        else cout << "no\n";
    } while(1);
}