/*
    https://www.acmicpc.net/problem/2151
    거울 설치
*/


#include <cstring>
#include <iostream>
using namespace std;

#define MAX_N 50

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct Node {
    int y, x;
};

int N;
char arr[MAX_N][MAX_N + 1];
int visited[MAX_N][MAX_N][4];
int answer = MAX_N * MAX_N;
Node door = {-1, -1};

void printDebug(int y, int x) {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == y && j == x)
                cout << 'X';
            else
                cout << arr[i][j];
        }
        cout << '\n';
    }
    char c;
    cin >> c;
}

void dfs(Node now, int dir, int mirror) {
    if (answer <= mirror) return;
    if (visited[now.y][now.x][dir]!=-1 && visited[now.y][now.x][dir] < mirror)
        return;
    visited[now.y][now.x][dir] = mirror;
    printDebug(now.y, now.x);

    int ny = now.y + dy[dir];
    int nx = now.x + dx[dir];
    if(ny < 0 || ny >= N || nx < 0 || nx >= N) return;
    if(arr[ny][nx] == '*') return;
    else if (arr[ny][nx] == '.') {
        dfs({ny, nx}, dir, mirror);
    }
    else if (arr[ny][nx] == '#') {
        if(answer > mirror) answer = mirror;
        return;
    } else if (arr[ny][nx] == '!') {
        dfs({ny, nx}, dir, mirror);
        dfs({ny, nx}, (dir+1)%4, mirror+1);
        dfs({ny, nx}, (dir+3)%4, mirror+1);
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    cin >> N;

    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '#' && door.y == -1) {
                door = {i, j};
                arr[i][j] = '*';
            }
        }
    }

    for (int d = 0; d < 4; d++) dfs({door.y, door.x}, d, 0);

    cout << answer;

    return 0;
}