#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int MAXN = 1000;

char arr[MAXN][MAXN + 1];
int N, M, result = -1;

// 방향별로 배열 만드는것
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0,1 ,0, -1 };

// 범위 벗어나는 거 방지하는 함수
bool inrange(int y, int x) {
    return y >= 0 && y < N&&x >= 0 && x < M;
}

int dist1[MAXN][MAXN];
int dist2[MAXN][MAXN];
bool visited1[MAXN][MAXN];
bool visited2[MAXN][MAXN];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", arr[i]);

    queue<P> q;
    // 시작점을 q에 넣는다.
    q.push({ 0, 0 });
    dist1[0][0] = 1;
    visited1[0][0] = true;

    while (!q.empty()) {
        // 한 노드를 큐에서 뺀다.
        int uy = q.front().first, ux = q.front().second;
        q.pop();
        // 뽑은 노드와 인접한 노드를 탐색한다. 그 노드들 중에서 아직 방문 안한 노드들을 큐에 넣는다.
        for (int d = 0; d < 4; ++d) {
            int vy = uy + dy[d], vx = ux + dx[d];
            if (!inrange(vy, vx) || arr[vy][vx] == '1' || visited1[vy][vx]) continue;
            dist1[vy][vx] = dist1[uy][ux] + 1;
            visited1[vy][vx] = true;
            q.push({ vy,vx });
        }
    }

    if(dist1[N-1][M-1] != 0) result = dist1[N-1][M-1];

    // 마지막 점을 q에 넣음
    q.push({N-1, M-1});
    dist2[N-1][M-1] = 1;
    visited2[N-1][M-1] = true;

    while (!q.empty()) {
        // 한 노드를 큐에서 뺀다.
        int uy = q.front().first, ux = q.front().second;
        q.pop();
        // 뽑은 노드와 인접한 노드를 탐색한다. 그 노드들 중에서 아직 방문 안한 노드들을 큐에 넣는다.
        for (int d = 0; d < 4; ++d) {
            int vy = uy + dy[d], vx = ux + dx[d];
            if (!inrange(vy, vx) || arr[vy][vx] == '1' || visited2[vy][vx]) continue;
            dist2[vy][vx] = dist2[uy][ux] + 1;
            visited2[vy][vx] = true;
            q.push({ vy, vx });
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] != '1') continue; // 벽이 아니면 pass
            int min1 = -1, min2 = -1;
            for(int d = 0; d < 4; d++) { // 현재 벽 기준 4 방향에 대한 distance 최솟값 찾기
                int vy = i + dy[d], vx = j + dx[d];
                if(inrange(vy, vx) && dist1[vy][vx] != 0) {
                    if(min1 == -1 || dist1[vy][vx] < min1) min1 = dist1[vy][vx];}
                if(inrange(vy, vx) && dist2[vy][vx] != 0) {
                    if(min2 == -1 || dist2[vy][vx] < min2) min2 = dist2[vy][vx];}
            }
            if(min1 > 0 && min2 > 0 && (result < 0 || min1 + min2 + 1 < result)) result = min1 + min2 + 1;
        }
    }

    printf("%d\n", result);
    
/******************
 * input과 distance1, 2를 출력해주는 좋은 녀석들 
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%2c ", arr[i][j]);
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%2d ", dist1[i][j]);
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%2d ", dist2[i][j]);
        }
        cout << endl;
    }
*********************/
}