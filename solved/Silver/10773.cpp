/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <stack>

using namespace std;

/* ���� */
#define MAX_K 100000

/* ���� */
int K, tmp, result = 0;
stack<int> s;

/* �Լ� */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> K;

    /* Ǯ�� */
    for(int i = 0; i < K; i++) {
        cin >> tmp;
        if(tmp == 0) s.pop();
        else s.push(tmp);
    }

    /* ��� */
    for(int i = s.size(); i > 0; i--) {
        result += s.top();
        s.pop();
    }
    cout << result << '\n';
}