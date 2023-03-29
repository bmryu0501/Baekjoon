/************************************
 * Author: Byeongmin Ryoo           *
 * Blog: https://velog.io/@kkoala   *
 * Contact: bmformail@naver.com     *
 ************************************/

#include <iostream>

using namespace std;

/* 조건 */
#define MIN -1000000000
#define MAX 1000000000

/* 변수 */
int N, input[11], op[4];
int output_min = MAX, output_max = MIN;

/* 함수 */
void tracker(int ans, int count) {
    if(count == N - 1) {
        if(output_min > ans) output_min = ans;
        if(output_max < ans) output_max = ans;
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(op[i] > 0) {
            switch(i) {
                case 0: op[i]--; tracker(ans + input[count+1], count + 1); break;
                case 1: op[i]--; tracker(ans - input[count+1], count + 1); break;
                case 2: op[i]--; tracker(ans * input[count+1], count + 1); break;
                case 3: op[i]--; tracker(ans / input[count+1], count + 1); break;
            }
            op[i]++;
        }
    }
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    /* 풀이 */
    tracker(input[0], 0);
    
    /* 출력 */
    cout << output_max << '\n' << output_min << '\n';
}