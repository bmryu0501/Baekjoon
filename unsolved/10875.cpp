#include <iostream>
using namespace std;

#define INF 21e8
#define MAX_L 100000000
#define MAX_N 100

int dy[4] = {0, 1, 0, -1}; // 홀수: 상하
int dx[4] = {1, 0, -1, 0}; // 짝수: 좌우

struct Line{
    int y, x;
    int len;
    int dir;
};

int L, N;
Line lines[MAX_N];
int y, x, len, dir, cur_time;
int ans = INF;

int check(int idx) {
    Line* now = &lines[idx];
    if(y < -MAX_L) return cur_time - (MAX_L - now->y);
    else if(y > MAX_L) return cur_time + (MAX_L - now->y);
    else if(x < -MAX_L) return cur_time - (MAX_L - now->x);
    else if(x > MAX_L) return cur_time + (MAX_L - now->x);
    for(int i=0;i<idx;i++) {
        Line* target = &lines[i];

        if(now->dir%2 == target->dir%2) { // 방향이 같다
            // 같은 선상에 없으면 만날 수 없다
            if(now->x != target->x && now->y != target->y) return 0;

            if(now->x == target->x && now->y != target->y) { // x만 같은 경우
                
            }
        } else { // 방향이 다르다
            
        }
    }

    return 0;
}

int main() {
    cin >> L >> N;

    char turn;
    for(int i=0;i<N;i++) {
        cin >> len >> turn;
        lines[i].y = y;
        lines[i].x = x;
        lines[i].len = len;
        lines[i].dir = dir;

        y += dy[dir] * len;
        x += dx[dir] * len;
        if(turn == 'L') dir = (dir + 5) % 4;
        else dir = (dir + 1) % 4;

        Line* now = &lines[i];

        ans = check(i);
        if(ans) break;

        cur_time += len;
    }

    cout << ans;

    return 0;
}
