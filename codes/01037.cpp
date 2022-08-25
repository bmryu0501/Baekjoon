/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MIN_FACTOR 1
#define MAX_FACTOR 1000000

/* ���� */
int N;
int min_factor = MAX_FACTOR, max_factor = MIN_FACTOR;

/* �Լ� */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> N;
    for(int i = 0, tmp; i < N; i++) {
        cin >> tmp;
        if(tmp > max_factor) max_factor = tmp;
        if(tmp < min_factor) min_factor = tmp;
    }

    /* Ǯ�� */

    /* ��� */
    cout << max_factor * min_factor << '\n';
}