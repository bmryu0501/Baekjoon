/*
1012 유기농 배추
그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색
*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_M 50
#define MAX_N 50

int T, M, N, K, cnt;
bool field[MAX_N][MAX_M];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init() {
    memset(field, 0, sizeof(field));
    cnt = 0;
}

void dfs(int y, int x) {
    field[y][x] = 0;

    int cy, cx;

    for(int i=0;i<4;i++) {
        cy = y + dy[i];
        cx = x + dx[i];

        if(cy>=0&&cy<N&&cx>=0&&cx<M&&field[cy][cx]) dfs(cy, cx);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> T;
    while(T--) {
        init();
        cin >> M >> N >> K;
        int X, Y;
        for(int i=0;i<K;i++) {
            cin >> X >> Y;
            field[Y][X] = true;
        }

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            if(field[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }

        cout << cnt << '\n';
    }
}