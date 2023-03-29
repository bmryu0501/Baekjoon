/************************************
 * Author: Byeongmin Ryoo           *
 * Blog: https://velog.io/@kkoala   *
 * Contact: bmformail@naver.com     *
 ************************************/

#include <iostream>

using namespace std;

/* ���� */
#define MAX 15

/* ���� */
int N, ans = 0;
bool board[MAX][MAX]; // queen�� ������ ��� true

/* �Լ� */
bool isAvailable(int x, int y) {
    // ���� ���� Ȯ��
    for(int i = 0; i < N; i++) {
        if(board[x][i] == true) return false; // x������ �����̹Ƿ� ��� �ʿ� X
        if(board[i][y] == true) return false;
    }
    // �밢�� Ȯ��
    for(int i = 0, j; i < N; i++) {
        j = y - x + i;
        if(j >= 0 && j < N && board[i][j] == true) return false;
        j = y + x - i;
        if(j >= 0 && j < N && board[i][j] == true) return false;
    }
    return true;
}

void putQueen(int x, int y, int count) { // (x, y)�� ����. count�� ���� Ƚ��
    if(isAvailable(x, y)) { // ���� �� �ִ� ���
        if(count == N) { // ��� ���� ���
            ans++;
            return;
        }
        board[x][y] = true; // queen�� ����
        for(int i = 0; i < N; i++) // x + 1�ٿ� ���ƺ�
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

    /* �Է� */
    cin >> N;

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            board[i][j] = false;
        }
    }

    /* Ǯ�� */
    for(int i = 0; i < N; i ++) {
        putQueen(0, i, 1); // x = (0, i)�� '1��°'�� ����
    }

    /* ��� */
    cout << ans << '\n';
}