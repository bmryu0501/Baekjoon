/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MAX_LENGTH 51

/* 변수 */
int num = 0, result = 0;
bool isPlus = true;
string expression;
char symbol;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> expression;

    /* 풀이 */
    int exp_len;
    exp_len = expression.length();

    for(int i = 0; i < exp_len; i++) {
        if(isdigit(expression[i])) {
            num *= 10;
            num += expression[i] - '0';
        } else {
            if(isPlus) {
                result += num;
                num = 0;
            } else {
                result -= num;
                num = 0;
            }
            if(expression[i] == '-') isPlus = false;
        }
    }

    if(isPlus) {
        result += num;
        num = 0;
    } else {
        result -= num;
        num = 0;
    }

    /* 출력 */
    cout << result;
}