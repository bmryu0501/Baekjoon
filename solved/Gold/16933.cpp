#include <iostream>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;

#ifdef BOJ
#define DEBUG 0
#else
#define DEBUG 1
#endif

#define MAX_N 1004
#define MAX_M MAX_N
#define MAX_K 11

#define DAY 0
#define NIGHT 1

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

typedef struct Point {
    int y, x;
    unsigned int cost;
    int time;
    int k;
} Point;

int N, M, K;
char arr[MAX_N][MAX_M];
int visited[MAX_N][MAX_M][MAX_K];
queue<Point> q;

int go(){
    q.push({0, 0, 1, DAY, 0});
    visited[0][0][0] = 1;

#if DEBUG
printf("y\tx\tcost\ttime\tk\n");
#endif

    while(!q.empty()) {
        Point now = q.front();
        q.pop();
#if DEBUG
printf("%d\t%d\t%d\t%d\t%d\n", now.y, now.x, now.cost, now.time, now.k);
#endif

        if(now.y == N-1 && now.x == M-1) return now.cost;

        for(int d=0;d<4;++d) {
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if(arr[ny][nx] == '0') {
                if(visited[ny][nx][now.k] > 0) continue;
                q.push({ny, nx, now.cost+1, now.time==DAY?NIGHT:DAY, now.k});
                visited[ny][nx][now.k] = 1;
            } else if(now.k < K) {
                //q.push({ny, nx, now.cost+now.time+1, NIGHT, now.k+1});
                if(visited[ny][nx][now.k+1]) continue;
                if(now.time == NIGHT) {
                    q.push({now.y, now.x, now.cost+1, DAY, now.k});
                    visited[now.y][now.x][now.k] = 1;
                } else {
                    q.push({ny, nx, now.cost+1, NIGHT, now.k+1});
                    visited[ny][nx][now.k+1] = 1;
                }
            }
        }
    }

    return -1;
}

int main() {
#if DEBUG
freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M >> K;
    for(int i=0;i<N;++i) cin >> arr[i];

#if DEBUG
//for(int i=0;i<N;++i) cout << arr[i] << "\n";
#endif

    cout << go();

    return 0;
}