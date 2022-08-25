/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_m 2000000000
#define MAX_n 2000000000

/* 변수 */
long long m, n;
long long result;

/* 함수 */
long long number_of_2(long long num) {
    long long count = 0;
    for(long long i = 2; i <= num; i *= 2) count += num / i;

    return count;
}
long long number_of_5(long long num) {
    long long count = 0;
    for(long long i = 5; i <= num; i *= 5) count += num / i;

    return count;
}
int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> n >> m;

    /* 풀이 */
    result = min(number_of_2(n) - number_of_2(m) - number_of_2(n - m), \
                 number_of_5(n) - number_of_5(m) - number_of_5(n - m));

    /* 출력 */
    cout << result << '\n';
}