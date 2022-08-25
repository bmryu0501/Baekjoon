/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MAX_N 10001

/* ���� */
int lhs, rhs;

/* �Լ� */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */

    /* Ǯ�� */
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

    /* ��� */
}