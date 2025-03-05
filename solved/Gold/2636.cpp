#include <iostream>
#include <queue>

using namespace std;

#ifdef BOJ
#define DEBUG 0
#else
#define DEBUG 1
#endif

#define MAX_SIZE 105

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

typedef struct Cheese {
    int y, x;
    int hour;

    bool operator<(const Cheese c) const {
        return hour > c.hour;
    }
} Cheese;

int N, M;
int arr[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int val[MAX_SIZE][MAX_SIZE];
priority_queue<Cheese> pq;

int max_val = -1;
int answer;

int main() {
#if DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> N >> M;
    for(int i=0;i<N;++i)for(int j=0;j<M;++j) cin >> arr[i][j];

    pq.push({0, 0, 0});
    visited[0][0] = true;
    while(!pq.empty())
    {
        Cheese now = pq.top();
        pq.pop();

        for(int d=0;d<4;++d)
        {
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = true;
            val[ny][nx] = now.hour + arr[ny][nx];
            pq.push({ny, nx, val[ny][nx]});
        }
    }
#if DEBUG
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) cout << val[i][j] << " ";
        cout << "\n";
    }
#endif

    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) max_val = max(max_val, val[i][j]);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) if(val[i][j] == max_val && arr[i][j]) answer++;

    cout << max_val << "\n" << answer;

    return 0;
}