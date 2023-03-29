#include <iostream>
#include <queue>
#define MAX_N 20

using namespace std;

struct Fish{
    int y, x;
    int size;

    bool operator < (Fish f) const {
        if(size == f.size) {
            if(y == f.y) return x > f.x;
            return y > f.y;
        }
        return size > f.size;
    }
};

int N;
int arr[MAX_N][MAX_N];
Fish shark;
int sec;
int ate;

// 상 좌 우 하
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

void printDebug() {
    cout << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i == shark.y && j == shark.x) cout << "X" << ' ';
            else if (arr[i][j] > 0) cout << arr[i][j] << ' ';
            else cout << '.' << ' ';
        }
        cout << '\n';
    }
    cout << sec << "s / Lv. " << shark.size << " (Exp " << ate << " / " << shark.size << ")\n";
}

bool bfs() {
    // 한 번 위치 옮기기
    // 못옮기면 return false;
    int visited[MAX_N][MAX_N] = {0, };
    
    priority_queue<Fish> q;
    q.push(shark);
    visited[shark.y][shark.x] = 1;

    while(!q.empty()) {
        Fish now = q.top(); q.pop();

        if(arr[now.y][now.x] < shark.size && arr[now.y][now.x] != 0) {
            if(++ate == shark.size) {
                shark.size++;
                ate = 0;
            }
            shark.y = now.y;
            shark.x = now.x;
            arr[shark.y][shark.x] = 0;
            sec += visited[now.y][now.x]-1;
            return true;
        }

        int ny, nx;
        for(int d=0;d<4;d++) {
            ny = now.y + dy[d];
            nx = now.x + dx[d];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(visited[ny][nx]) continue;
            if(arr[ny][nx] > shark.size) continue;

            // bfs 탐색
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ny, nx, visited[ny][nx]});
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
        cin >> arr[i][j];
        if(arr[i][j] == 9) {
            shark = {i, j, 2};
            arr[i][j] = 0;
        }
    }

    while(bfs()) {
        //printDebug();
    }

    cout << sec;
}