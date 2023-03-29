/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MAX_T 1000
#define MAX_VALUE 45000

/* ���� */
int T;
int A, B;
int dividend, divisor, remainder;
int GCF, LCM; // Great Common Facotr, Least Common Multiple

/* �Լ� */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> T;

    /* Ǯ�� */
    for(int i = 0; i < T; i ++) {
        cin >> A >> B;
        if(A < B) swap(&A, &B);
        
        dividend = A;
        divisor = B;

        while(remainder = dividend % divisor) {
            dividend = divisor;
            divisor = remainder;
        }

        GCF = divisor;
        LCM = A * B / GCF;

        cout << LCM << '\n';
    }

    /* ��� */
}