#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 12
#define MAX_K 10

using namespace std;

struct Piece {
    int num;
    int y, x;
    int dir;

    int upside, downside;
};

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
int nd[5] = {0, 2, 1, 4, 3};

int N, K;
int arr[MAX_N+1][MAX_N+1]; // 맵 구조. white = 0, red = 1, blue = 2;
int pieces[MAX_N+1][MAX_N+1]; // 바닥에 있는 말 index
Piece p[MAX_K+1];

int main() {
    cin >> N >> K;
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++) cin >> arr[i][j];
    int y, x, dir;
    for(int i=1;i<=K;i++) {
        cin >> y >> x >> dir;
        pieces[y][x] = i;
        p[i] = {i, y, x, dir, 0, 0};
    }

    int turn = 0;
    bool finished = false;
    while(turn++ < 1000 && !finished) {
        for(int i=1;i<=K;i++) { // 모든 기물 순서대로
            // 아래에 있지 않을 경우 continue
            if(p[i].downside != 0) continue;

            // 이동 위치 설정
            int ny = p[i].y + dy[p[i].dir];
            int nx = p[i].x + dx[p[i].dir];

            // 처음 벽/blue 만난 경우
            if(ny < 1 || ny > N || nx < 1 || nx > N || arr[ny][nx] == 2) {
                // 방향 바꾸고 이동 위치 재설정
                p[i].dir = nd[p[i].dir];
                ny = p[i].y + dy[p[i].dir];
                nx = p[i].x + dx[p[i].dir];
            }

            // 다시 blue일 경우 continue
            if(ny < 1 || ny > N || nx < 1 || nx > N || arr[ny][nx] == 2) continue;

            /* 이동하는 경우 */
            int now = i;
            if(arr[ny][nx] == 1) { // 이동하려는 칸이 빨간색인 경우
                while(now != 0) {
                    if(p[now].upside == 0) pieces[p[i].y][p[i].x] = now; // 현재 위치 bottom 재설정
                    int tmp = p[now].upside;
                    p[now].upside = p[now].downside;
                    p[now].downside = tmp;
                    now = tmp; // 위로 올라가면서 upside/downside 바꿔줌
                }
            }

            int bottom = pieces[p[i].y][p[i].x]; // pieces[p[i].y][p[i].x]에는 맨 아래 기물이 있음

            if(pieces[ny][nx]) { // 이동 위치에 기물이 있는 경우
                int top = pieces[ny][nx]; // 맨 위를 찾기 위해 bottom부터 시작
                while(p[top].upside != 0) top = p[top].upside; // top은 (ny, nx)의 가장 윗 기물

                p[bottom].downside = top;
                p[top].upside = bottom;
            } else { // 이동 위치에 기물이 없으면 맨 아래 업데이트
                pieces[ny][nx] = bottom;
            }

            pieces[p[i].y][p[i].x] = 0; // 내 위치 지워줌

            // 이동
            now = bottom; // now는 현 위치 가장 아래 기물부터
            while(now != 0) { // 맨 위에 도달 할 때 까지
                p[now].y = ny;
                p[now].x = nx;
                now = p[now].upside;
            }

            // 모든 process 종료. 기물 개수 확인
            now = pieces[ny][nx]; // now는 bottom부터 시작
            int count = 0; // 기물 개수
            while(now != 0) { // 맨 위에 도달 할 때 까지
                count++; // 기물 count
                now = p[now].upside;
            }

            if(count >= 4) finished = true; // 기물이 4개 이상인 경우 finished
        }
    }

    if(turn > 1000) cout << -1;
    else cout << turn-1;

    return 0;
}