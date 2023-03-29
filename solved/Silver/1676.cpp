/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_N 500

/* 변수 */
int N;
int count_5 = 0;
int count_2 = 0;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;

    /* 풀이 */
    for(int i = 2, num; i <= N; i++) {
        num = i;
        while(num % 2 == 0) {
            num /= 2;
            count_2++;
        }
        while(num % 5 == 0) {
            num /= 5;
            count_5++;
        }
    }

    /* 출력 */
    cout << min(count_2, count_5) << '\n';
}