/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MAX_N 11
#define MAX_K 100000001

/* ���� */
int N, K;
int coin[MAX_N];
int count = 0;

/* �Լ� */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    /* Ǯ�� */
    for(int i = N-1; i >= 0; i--) {
        if(K == 0) break;
        if(K >= coin[i]) {
            count += K / coin[i];
            K %= coin[i];
        }
    }

    /* ��� */
    cout << count;
}