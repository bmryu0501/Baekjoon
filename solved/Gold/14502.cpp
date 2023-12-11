#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAX_N 8
#define MAX_M 8

struct Coordinate{
    int y, x;
};

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int N, M;
int arr[MAX_N][MAX_M];
bool visit[MAX_N][MAX_M];
int num_virus;
Coordinate viruses[MAX_N * MAX_M];
int num_safe;
int answer;

bool isValid(int y, int x) {
    if(x < 0 || x >= M || y < 0 || y >= N) return false;
    return true;
}
bool tmp = true;

void bfs() {
    memset(visit, 0, sizeof(visit));
    int infected = 0;

    queue<Coordinate> q;
    for(int i=0;i<num_virus;i++) {
        q.push(viruses[i]);
        visit[viruses[i].y][viruses[i].x] = 1;
    }

    while(!q.empty()) {
        Coordinate now = q.front();
        q.pop();

        for(int d=0;d<4;d++) {
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];
            if(isValid(ny, nx) && !visit[ny][nx] && arr[ny][nx] == 0) {
                q.push({ny, nx});
                visit[ny][nx] = true;
                infected++;
            }
        }
    }
    
    answer = max(answer, num_safe - infected);
}

void solve(int wy, int wx, int cnt) {
    if(cnt == 3) {
        bfs();
        return;
    }


    for(int i=wy;i<N;++i) for(int j=(i==wy?wx:0);j<M;++j) {
        if(arr[i][j] == 0) {
            arr[i][j] = 1;
            solve(i, j, cnt+1);
            arr[i][j] = 0;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /* input */
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) viruses[num_virus++] = {i, j};
            if(arr[i][j] == 0) num_safe++;
        }
    }

    /* solving */
    num_safe -= 3;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++) {
        if(arr[i][j] == 0) {
            arr[i][j] = 1;
            solve(i, j, 1);
            arr[i][j] = 0;
        }
    }

    /* output */
    cout << answer;
}