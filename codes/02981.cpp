/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <algorithm>
using namespace std;

/* ���� */
#define MAX_N 100
#define MAX_NUM 1000000000

/* ���� */
int N;
int arr[MAX_N + 1];
int gcd;

/* �Լ� */
int GCD(int a, int b) {
    if(a % b == 0) return b;
    return GCD(b, a%b);
}

void printDivisors(int n) {
    for(int i = 2; i < n / 2; i++) {
        if(n % i == 0)
            cout << i << ' ';
    }
    if(n % 2 == 0) cout << n/2 << ' ';
    cout << n << '\n';
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    /* Ǯ�� */
    gcd = arr[1] - arr[0];
    for(int i = 2; i < N; i++) {
        if(arr[i] - arr[0] % gcd == 0) continue;
        gcd = GCD(arr[i] - arr[0], gcd);
    }

    /* ��� */
    printDivisors(gcd);
}