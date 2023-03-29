/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MAXINPUT 1000001
const int devisor = 15746;

/* ���� */
int N;
int arr[MAXINPUT] = {0, };

/* �Լ� */
int func(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    if(arr[n] == 0) {
        arr[n] = (func(n - 1) + func(n - 2)) % devisor;
    }
    return arr[n] % devisor;
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> N;

    /* Ǯ�� */
    cout << func(N);
}