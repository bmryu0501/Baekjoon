/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MAX_INPUT 41

/* ���� */
int T, N;
int fibo[MAX_INPUT][2]; 

/* �Լ� */
void makeFiboArray() {
    fibo[0][0] = 1;
    fibo[0][1] = 0;
    fibo[1][0] = 0;
    fibo[1][1] = 1;
    for(int i = 2; i < 41; i++) {
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }
}

void printResult(int n) {
    cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* Ǯ�� */
    makeFiboArray();

    /* �Է� */
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        printResult(N);
    }

    /* ��� */
}