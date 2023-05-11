#include <iostream>
using namespace std;

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

int main() {
    cin >> L >> N;
    int y = 0;
    int x = 0;
    int len;
    int dir = 0;
    char turn;
    int time = 0;

    for(int i=0;i<N;i++) {
        int hit = 2e8;

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

        for(int j=0;j<i;j++) {
            Line* target = &lines[j];

            
        }

        if(hit < 1000) {
            time += hit;
            break;
        }

        time += len;
    }

    return 0;
}
