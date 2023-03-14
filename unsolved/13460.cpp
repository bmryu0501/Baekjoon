#include <iostream>

#define MAX_N 10
#define MAX_M 10

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Node{
    int y, x;
};

int N, M;
char arr[MAX_N][MAX_M+1];
Node hole;
int answer = 11;

void dfs(int level, Node red, Node blue) {
    if(level == 11 || answer < level) return;

    for(int d=0;d<4;d++) {
        int ry = red.y;
        int rx = red.x;
        int by = blue.y;
        int bx = blue.x;

        bool escapeR = false;
        bool escapeB = false;

        arr[red.y][red.x] = '.';
        while(ry >= 0 && ry < N && rx >= 0 && rx < M && arr[ry][rx] == '.') {
            ry += dy[d];
            rx += dx[d];
        }
        ry -= dy[d];
        rx -= dx[d];
        arr[ry][rx] = 'R';

        arr[blue.y][blue.x] = '.';
        while(by >= 0 && by < N && bx >= 0 && bx < M && arr[by][bx] == '.') {
            by += dy[d];
            bx += dx[d];
        }
        by -= dy[d];
        bx -= dx[d];
        arr[by][bx] = 'B';

        while(ry >= 0 && ry < N && rx >= 0 && rx < M && arr[ry][rx] == '.') {
            ry += dy[d];
            rx += dx[d];
        }
        while(by >= 0 && by < N && bx >= 0 && bx < M && arr[by][bx] == '.') {
            by += dy[d];
            bx += dx[d];
        }
    }
}

int main() {
    cin >> N >> M;
    Node red, blue;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        for(int j=0;j<M;j++) {
            if(arr[i][j] == 'B') blue = {i, j};
            else if(arr[i][j] == 'R') red = {i, j};
            else if(arr[i][j] == 'O') hole = {i, j};
        }
    }

    dfs(0, red, blue);

    return 0;
}