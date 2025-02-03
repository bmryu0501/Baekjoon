/*
18500 미네랄 2
https://www.acmicpc.net/problem/18500
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX_R 100
#define MAX_C 100

using namespace std;

#define DOWN 3
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

struct Node{
    int y, x;
};

int R, C, N;
char arr[MAX_R][MAX_C+1];

int getC(int r, bool turn) {
    for(int i = C * turn - turn; i != C * !turn - turn; i += !turn - turn) {
        if(arr[r][i] == 'x') return i;
    }
    return -1;
}

int main() {
    cin >> R >> C;
    for(int i=0;i<R;i++) cin >> arr[i];

    cin >> N;
    int r, c;
    int turn = 1;
    while(N--) {
        turn = !turn;
        cin >> r;
        r = R-r;
        c = getC(r, turn);
        if(c == -1) continue;

        arr[r][c] = '.';

        for(int d=0;d<4;d++) {
            bool visited[MAX_R][MAX_C] = {0, };
            int ny = r + dy[d];
            int nx = c + dx[d];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || arr[ny][nx] == '.') continue;

            queue<Node> q;
            vector<Node> cluster;
            q.push({ny, nx});
            cluster.push_back({ny, nx});
            visited[ny][nx] = true;

            bool isOnGround = false;
            while(!q.empty()) {
                Node now = q.front(); q.pop();
                if(now.y == R-1) {
                    isOnGround = true;
                    break;
                }

                visited[now.y][now.x] = true;

                for(int i=0;i<4;i++) {
                    int ny = now.y + dy[i];
                    int nx = now.x + dx[i];
                    if(ny < 0 || ny >= R || nx < 0 || nx >= C || arr[ny][nx] == '.') continue;
                    if(visited[ny][nx]) continue;
                    q.push({ny, nx});
                    cluster.push_back({ny, nx});
                    visited[ny][nx] = true;
                }
            }

            if(isOnGround) continue;

            int minDown = R;
            for(int i=0;i<cluster.size();i++) {
                int y = cluster[i].y;
                int x = cluster[i].x;
                int down = 0;
                while(y+down+1 < R && arr[y+down+1][x] == '.') down++;
                if(visited[y+down+1][x]) continue;
                minDown = min(minDown, down);
            }

            for(Node n : cluster) {
                arr[n.y][n.x] = '.';
            }
            for(Node n : cluster) {
                arr[n.y+minDown][n.x] = 'x';
            }
        }
        
        // cout << '\n';
        // for(int i=0;i<R;i++) cout << arr[i] << '\n';
    }

    for(int i=0;i<R;i++) cout << arr[i] << '\n';

    return 0;
}