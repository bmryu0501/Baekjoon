/************************************
 * Author: Byeongmin Ryoo           *
 * Blog: https://velog.io/@kkoala   *
 * Contact: bmformail@naver.com     *
 ************************************/

#include <iostream>

using namespace std;

/* ���� */

/* ���� */
int board[9][9];

/* �Լ� */
void printBoard();
bool isAvailable(int x, int y, int n) {
    for(int i = 0; i < 9; i++) {
        if(board[x][i] == n) return false; // ���� Ȯ��
        if(board[i][y] == n) return false; // ���� Ȯ��
        for(int a = 0; a < 3; a++) // ���簢�� Ȯ��
            for(int b = 0; b < 3; b++)
                if(board[((x/3)*3) + a][((y/3)*3) + b] == n) return false;
    }
    return true;
}

void solve(int x, int y) {
    if(board[x][y] == 0) { // ��ĭ�� ���
        for(int i = 1; i <= 9; i++) { // 1���� 9���� �־
            if(isAvailable(x, y, i)) { // �־ �Ǵ� ���
                board[x][y] = i; // ���ڸ� �־
                if(x == 8 && y == 8) printBoard(); // ������ ĭ���� ���� ��� ����� ����
                solve(x + ((y+1) / 9), (y+1) % 9); // ���� ĭ Ȯ��
                board[x][y] = 0;
            }
        }
    } else { // ��ĭ�� �ƴ� ���
        if(x == 8 && y == 8) printBoard(); // �������� ������ ��� ��� �� ����
        solve(x + ((y+1) / 9), (y+1) % 9); // ���� ĭ Ȯ��
    }
}

void printBoard() { // ��ü ��� �� �����ϴ� �Լ�
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

    /* �Է� */
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j]; // ���ΰ� x�� ���ΰ� y��
        }
    }

    /* Ǯ�� */
    solve(0, 0); // (0, 0)���� ����

    /* ��� */
    /* solve()���� ������ ä�� ���
     * printBoard() �����Ͽ� ��µ� */
}