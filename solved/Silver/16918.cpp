/*
16918번 봄버맨
https://www.acmicpc.net/problem/16918
구현
그래프 이론
그래프 탐색
시뮬레이션
*/

#include <iostream>
#include <queue>
using namespace std;
#define MAX_R 200
#define MAX_C 200
#define MAX_N 200

#define DEBUG 1

struct Point {
    int y, x;
};

int R, C, N;
int arr[MAX_R][MAX_C];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    cin >> R >> C >> N;

    queue<Point> q;

    char t;
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
        cin >> t;
        if(t == 'O') arr[i][j] = 2;
        else arr[i][j] = 0;
    }

    while(--N) {
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) {
            arr[i][j]++;
            if(arr[i][j] == 4) q.push({i, j});
        }

        while(!q.empty()) {
            Point p = q.front();
            q.pop();

            arr[p.y][p.x] = 0;
            
            int ny, nx;

            for(int d=0;d<4;d++) {
                ny = p.y + dy[d];
                nx = p.x + dx[d];
                if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                arr[ny][nx] = 0;
            }
        }

        if(DEBUG) {
            cout << "[" << N << "]\n";
            for(int i=0;i<R;i++) {
                for(int j=0;j<C;j++) cout << arr[i][j];
                cout << '\n';
            }
            cout << "\n";
        }
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(arr[i][j]) cout << "O";
            else cout << ".";
        }
        cout << '\n';
    }

    return 0;
}