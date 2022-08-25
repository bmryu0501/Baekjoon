/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* ���� */
#define MAX_N 10000

/* ���� */
int N;
stack<int> s;

/* �Լ� */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> N;

    /* Ǯ�� */
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;

        if(str == "push") {
            int tmp;
            cin >> tmp;
            s.push(tmp);
        } else if(str == "pop") {
            if(s.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << s.top() << '\n';
            s.pop();
        } else if(str == "size") {
            cout << s.size() << '\n';
        } else if(str == "empty") {
            cout << s.empty() << '\n';
        } else if(str == "top") {
            if(s.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << s.top() <<'\n';
        }
    }
}