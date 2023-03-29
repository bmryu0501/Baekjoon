/************************************
 * Author: Byeongmin Ryoo           *
 * Blog: https://velog.io/@kkoala   *
 * Contact: bmformail@naver.com     *
 ************************************/

#include <iostream>

using namespace std;

/* 조건 */

/* 변수 */
int board[9][9];

/* 함수 */
void printBoard();
bool isAvailable(int x, int y, int n) {
    for(int i = 0; i < 9; i++) {
        if(board[x][i] == n) return false; // 가로 확인
        if(board[i][y] == n) return false; // 세로 확인
        for(int a = 0; a < 3; a++) // 정사각형 확인
            for(int b = 0; b < 3; b++)
                if(board[((x/3)*3) + a][((y/3)*3) + b] == n) return false;
    }
    return true;
}

void solve(int x, int y) {
    if(board[x][y] == 0) { // 빈칸인 경우
        for(int i = 1; i <= 9; i++) { // 1부터 9까지 넣어봄
            if(isAvailable(x, y, i)) { // 넣어도 되는 경우
                board[x][y] = i; // 숫자를 넣어봄
                if(x == 8 && y == 8) printBoard(); // 마지막 칸까지 넣은 경우 출력후 종료
                solve(x + ((y+1) / 9), (y+1) % 9); // 다음 칸 확인
                board[x][y] = 0;
            }
        }
    } else { // 빈칸이 아닌 경우
        if(x == 8 && y == 8) printBoard(); // 마지막에 도달한 경우 출력 후 종료
        solve(x + ((y+1) / 9), (y+1) % 9); // 다음 칸 확인
    }
}

void printBoard() { // 전체 출력 후 종료하는 함수
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    exit(0);
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j]; // 세로가 x축 가로가 y축
        }
    }

    /* 풀이 */
    solve(0, 0); // (0, 0)에서 시작

    /* 출력 */
    /* solve()에서 끝까지 채운 경우
     * printBoard() 실행하여 출력됨 */
}