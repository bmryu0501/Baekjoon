/************************************
 * Author: Byeongmin Ryoo           *
 * Blog: https://velog.io/@kkoala   *
 * Contact: bmformail@naver.com     *
 ************************************/

#include <iostream>

using namespace std;

/* 조건 */
#define MAX 15

/* 변수 */
int N, ans = 0;
bool board[MAX][MAX]; // queen이 존재할 경우 true

/* 함수 */
bool isAvailable(int x, int y) {
    // 가로 세로 확인
    for(int i = 0; i < N; i++) {
        if(board[x][i] == true) return false; // x축으로 움직이므로 사실 필요 X
        if(board[i][y] == true) return false;
    }
    // 대각선 확인
    for(int i = 0, j; i < N; i++) {
        j = y - x + i;
        if(j >= 0 && j < N && board[i][j] == true) return false;
        j = y + x - i;
        if(j >= 0 && j < N && board[i][j] == true) return false;
    }
    return true;
}

void putQueen(int x, int y, int count) { // (x, y)에 넣음. count는 놓인 횟수
    if(isAvailable(x, y)) { // 놓을 수 있는 경우
        if(count == N) { // 모두 놓은 경우
            ans++;
            return;
        }
        board[x][y] = true; // queen을 놓고
        for(int i = 0; i < N; i++) // x + 1줄에 놓아봄
            putQueen(x+1, i, count+1);
        board[x][y] = false;
    } else return;

}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            board[i][j] = false;
        }
    }

    /* 풀이 */
    for(int i = 0; i < N; i ++) {
        putQueen(0, i, 1); // x = (0, i)에 '1번째'로 넣음
    }

    /* 출력 */
    cout << ans << '\n';
}