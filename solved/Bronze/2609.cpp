/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_VALUE 10001

/* 변수 */
int lhs, rhs;
int dividend, divisor, remainder;
int GCF, LCM; // Great Common Facotr, Least Common Multiple

/* 함수 */
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

    /* 입력 */
    cin >> lhs >> rhs;

    /* 풀이 */
    if(lhs < rhs) swap(&lhs, &rhs);

    dividend = lhs;
    divisor = rhs;

    while(remainder = dividend % divisor) {
        dividend = divisor;
        divisor = remainder;
    }
    GCF = divisor;

    LCM = lhs * rhs / GCF;

    /* 출력 */
    cout << GCF << '\n' << LCM << '\n';
}