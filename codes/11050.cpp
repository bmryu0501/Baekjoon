/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MAX_N 10

/* ���� */
int N, K;
int C[MAX_N+1][MAX_N+1];

/* �Լ� */
int combination(int n, int k) {
    if(C[n][k] > 0) return C[n][k];
    if(n == 0) return C[n][k] = 0;
    if(n == k) return C[n][k] = 1;
    if(k == 0) return C[n][k] = 1;
    return C[n][k] = combination(n-1, k-1) + combination(n-1, k);
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> N >> K;

    /* Ǯ�� */
    C[0][0] = 1;
    combination(N, K);

    /* ��� */
    cout << C[N][K];
}