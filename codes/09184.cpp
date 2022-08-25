/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>

using namespace std;

/* 조건 */
#define MIN_INPUT -50
#define MAX_INPUT 50

/* 변수 */
int input_a, input_b, input_c;
int memo[21][21][21]; //memoization 배열

/* 함수 */
int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if(memo[a][b][c] > 0) return memo[a][b][c];
    if(a < b && b < c) {
        memo[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return memo[a][b][c];
    } else {
        memo[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        return memo[a][b][c];
    }
    
}

int main() {
    // memo 초기화
    for(int x = 0; x < 21; x++)
        for(int y = 0; y < 21; y++)
            for(int z = 0; z < 21; z++)
                memo[x][y][z] = 0;

    /* 풀이 */
    while(1) {
        scanf("%d%d%d", &input_a, &input_b, &input_c);
        if(input_a == -1 && input_b == -1 && input_c == -1) break;

        cout << "w(" << input_a << ", " << input_b << ", " << input_c << ") = ";
        cout << w(input_a, input_b, input_c) << '\n';
    }
}