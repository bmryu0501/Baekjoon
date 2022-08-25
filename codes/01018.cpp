#include <iostream>

using namespace std;

int main() {
    int N, M, board[50][50] = {0, }, min  = 8 * 8, cnt;
    char tmp;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tmp;
            // B = 0, W = 1
            if(tmp == 'W') board[i][j] = 1;
        }
    }

    for(int i = 0; i < N - 7; i++) {
        for(int j = 0; j < M - 7; j++) {

            // Ã¹ Ä­À» 0À¸·Î
            cnt = 0;
            for(int n = i; n < i + 8; n++) {
                for(int m = j; m < j + 8; m++){
                    if((n + m) % 2 == 0) {
                        if(board[n][m] == 1) cnt++;
                    } else {
                        if(board[n][m] == 0) cnt++;
                    }
                }
            }
            if (cnt < min) min = cnt;

            // Ã¹ Ä­À» 1·Î
            cnt = 0;
            for(int n = i; n < i + 8; n++) {
                for(int m = j; m < j + 8; m++){
                    if((n + m) % 2 == 0) {
                        if(board[n][m] == 0) cnt++;
                    } else {
                        if(board[n][m] == 1) cnt++;
                    }
                }
            }
            if (cnt < min) min = cnt;
        }
    }

    printf("%d\n", min);
}