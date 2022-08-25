#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int MAXN = 100;

char arr[MAXN][MAXN + 1];
int N, M;
// 방향별로 배열 만드는것
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0,1 ,0, -1 };
// 범위 벗어나는 거 방지하는 함수
bool inrange(int y, int x) {
    return y >= 0 && y < N&&x >= 0 && x < M;
}

int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%s", arr[i]);

    queue<P> q;
    // 시작점을 q에 넣는다.
    q.push({ 0, 0 });
    dist[0][0] = 1;

    while (!q.empty()) {
        // 한 노드를 큐에서 뺀다.
        int uy = q.front().first, ux = q.front().second;
        q.pop();
        // 뽑은 노드와 인접한 노드를 탐색한다. 그 노드들 중에서 아직 방문 안한 노드들을 큐에 넣는다.
        for (int d = 0; d < 4; ++d) {
            int vy = uy + dy[d], vx = ux + dx[d];
            if (!inrange(vy, vx) || arr[vy][vx] == '0' || visited[vy][vx]) continue;
            dist[vy][vx] = dist[uy][ux] + 1;
            visited[vy][vx] = true;
            q.push({ vy,vx });
        }
    }
    printf("%d\n", dist[N - 1][M - 1]);

}