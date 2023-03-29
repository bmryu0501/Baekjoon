/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MAX_LINE 101
#define MAX_POS 501 // max position. �������� ��ġ�� �ִ� ����

/* ���� */
int N, arr[MAX_POS];
int dp[MAX_POS]; // �� arr[i]�� ���� LIS�� ����
int max_LIS = 0; // LIS��

/* �Լ� */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> N;
    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        cin >> arr[tmp];
        dp[i] = 1; // dp�� 1�� �ʱ�ȭ
    }

    /* Ǯ�� */
    for(int i = 0; i < MAX_POS; i++) {
        if(arr[i] == 0) { // A[i]�� ������ ���� ���
            dp[i] = 0;
            continue;
        }
        for(int j = 0; j < i; j++) { // dp[i]�� LIS ������Ʈ
            if(arr[j] < arr[i] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
                if(max_LIS < dp[i]) // max_LIS ������Ʈ
                    max_LIS = dp[i];
            }
        }
    }

    /* ��� */
    cout << N - max_LIS << '\n';
}