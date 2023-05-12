#include <iostream>
using namespace std;

#define INF 21e8
#define MAX_L 100000000
#define MAX_N 100

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct Line{
    int y, x;
    int len;
    int dir;
};

int L, N;
Line lines[MAX_N];
int y, x, len, dir, time;
int ans = INF;

bool check(int idx) {
    Line* now = &lines[idx];
    if(now->y < -MAX_L || now->y > MAX_L || now->x < -MAX_L || now->x > MAX_L) return false;


    return true;
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

        if(check(i)) break;

        time += len;
    }

    cout << ans;

    return 0;
}
