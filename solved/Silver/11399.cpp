/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <algorithm>

using namespace std;

/* ���� */
#define MAX_N 1001

/* ���� */
int N;
int arr[MAX_N];
int sum = 0;

/* �Լ� */

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

    /* Ǯ�� */
    sort(arr, arr+N);
    for(int i = 0; i < N; i++) {
        sum += arr[i];
        arr[i+1] += arr[i];
    }

    /* ��� */
    cout << sum << '\n';
}