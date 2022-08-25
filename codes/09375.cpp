/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

/* ���� */
#define MAX_testcase 100
#define MAX_n 30

/* ���� */
int testcase, n;
map<string, int> m;
string cloth, category;
map<string, int>::iterator iter;
int result;

/* �Լ� */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    cin >> testcase;
    for(int i = 0; i < testcase; i++) {
        /* �ʱ�ȭ */
        result = 1;
        m.clear();

        /* �Է� */
        cin >> n;

        for(int j = 0; j < n; j++) {
            cin >> cloth >> category;
            iter = m.find(category);
            if((iter = m.find(category)) == m.end()) m.insert(pair<string, int>(category, 1));
            else iter->second++;
        }

        /* Ǯ�� */
        for(iter = m.begin(); iter != m.end(); iter++) {
            result *= iter->second + 1;
        }

        /* ��� */
        cout << result - 1 << '\n';
    }
}