/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* ���� */
#define MAXINPUT 1001

/* ���� */
int N, cost[MAXINPUT][3];

/* �Լ� */
int min(int a, int b) {
    return a<b?a:b;
}

int main() {
    /* �Է� */
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d%d%d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    /* Ǯ�� */
    for(int i = 2; i <= N; i++) {
        cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] += min(cost[i-1][0], cost[i-1][1]);
    }

    /* ��� */
    printf("%d\n", min(min(cost[N][0], cost[N][1]), cost[N][2]));
}