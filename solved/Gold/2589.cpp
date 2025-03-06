#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#ifdef BOJ
#define DEBUG 0
#else
#define DEBUG 1
#endif

#define MAX_N 52
#define MAX_M MAX_N

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

typedef struct Point {
    int y, x;
    int val;
} Point;

int N, M;
char arr[MAX_N][MAX_M];
int answer = 0;

void go(int i, int j)
{
    queue<Point> q;
    bool visited[MAX_N][MAX_M];
    memset(visited, 0, sizeof(visited));
    q.push({i, j, 0});
    visited[i][j] = true;

    while(!q.empty())
    {
        Point now = q.front();
        q.pop();

        answer = max(answer, now.val);

        for(int d=0;d<4;++d)
        {
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(arr[ny][nx] == 'W') continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({ny, nx, now.val+1});
        }
    }
}

int main()
{
#if DEBUG
freopen("input.txt", "r", stdin);
#endif
    cin >> N >> M;

    for(int i=0;i<N;++i) cin >> arr[i];

    for(int i=0;i<N;++i) for(int j=0;j<M;++j)
    {
        if(arr[i][j] == 'W') continue;

        go(i, j);
    }

    cout << answer;

    return 0;
}