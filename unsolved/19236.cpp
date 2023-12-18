/*
19236번
청소년상어
https://www.acmicpc.net/problem/19236
*/

#include <iostream>
#include <string.h>
#include <utility>
using namespace std;

#define SIZE 4
#define SHARK 0

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct Fish{
    int y, x;
    int id;
    int dir;
    bool is_alive;
};

int loc[SIZE][SIZE];
Fish fishes[SIZE*SIZE+1];
int answer = 0;

int max(int a, int b) {
    return a>b?a:b;
}

void swap(int a, int b) {
    loc[fishes[a].y][fishes[a].x] = b;
    loc[fishes[b].y][fishes[b].x] = a;

    int y = fishes[a].y;
    int x = fishes[a].x;
    fishes[a].y = fishes[b].y;
    fishes[a].x = fishes[b].x;
    fishes[b].y = y;
    fishes[b].x = x;
}

bool isValid(int y, int x) {
    if(y < 0 || y >= SIZE || x < 0 || x >= SIZE) return false;
    return true;
}

void moveFish(int y, int x) {
    for(int i=1;i<=SIZE*SIZE;i++) {
        Fish* now = &fishes[i];
        if(!now->is_alive) continue;
        for(int d=0;d<8;d++) {
            int nd = (now->dir+d)%8;
            int ny = now->y + dy[nd];
            int nx = now->x + dx[nd];
            if(isValid(ny, nx) && !(ny == y && nx == x)) {
                now->dir = nd;
                swap(loc[now->y][now->x], loc[ny][nx]);
                break;
            }
        }
    }
}

void go(int y, int x, int dir, int count) {
    fishes[loc[y][x]].is_alive = false;
    count += fishes[loc[y][x]].id;
    int loc_ori[SIZE][SIZE];
    Fish fishes_ori[SIZE*SIZE+1];
    memcpy(loc_ori, loc, sizeof(loc));
    memcpy(fishes_ori, fishes, sizeof(fishes));

    moveFish(y, x);

    int ny = y;
    int nx = x;
    while(isValid(ny, nx)) {
        ny += dy[dir];
        nx += dx[dir];
        if(!isValid(ny, nx) || !fishes[loc[ny][nx]].is_alive) {
            answer = max(answer, count);
            continue;
        }
        go(ny, nx, fishes[loc[ny][nx]].dir, count);
    }

    fishes[loc[y][x]].is_alive = true;
    memcpy(loc, loc_ori, sizeof(loc));
    memcpy(fishes, fishes_ori, sizeof(fishes));
}

int main() {

    for(int i=0;i<SIZE;i++) for(int j=0;j<SIZE;j++) {
        int id, dir;
        cin >> id >> dir;
        fishes[id] = {i, j, id, dir-1, true};
        loc[i][j] = id;
    }

    go(0, 0, fishes[loc[0][0]].dir, 0);

    cout << answer;
    
    return 0;
}