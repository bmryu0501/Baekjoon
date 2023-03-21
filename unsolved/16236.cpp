/**********************************************************
*  16236 아기상어
*  구현, 그래프 이론, 그래프 탐색, 너비 우선 탐색, 시뮬레이션
***********************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>

/* math.h
#define _USE_MATH_DEFINES // need this to use math defines
#include <math.h>
*/

using namespace std;

/* condition */
#define MAX_N 20

/* variables */
int N, shark = 2;
int result = 0;
int arr[MAX_N][MAX_N];
pair<int, int> loc_of_shark;

// directions W N S E
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

/* functions */
// bfs
bool visit[MAX_N][MAX_N];

bool isPossible(int x, int y) {// check if location is possible or not
    if(visit[x][y]) return false;
    if(x < 0) return false;
    if(x >= N) return false;
    if(y < 0) return false;
    if(y >= N) return false;

    return true;
}

pair<int, int> bfs(pair<int ,int> start){
    /* init */
    int x, y, time;

    memset(visit, false, sizeof(visit));
    visit[start.first][start.second] = true;

    queue<pair<pair<int, int>, int>> q;
    while(!q.empty()) q.pop();
    q.push(make_pair(start, 0));

    /* find fish */
    while(!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        time = q.front().second;
        q.pop();

        if(arr[x][y] <= shark) {
            result += time;
            if(arr[x][y] == shark) shark++;
            arr[x][y] = 0;
            return make_pair(x, y);
        }

        for(int i=0;i<4;i++) {
            if(isPossible(x+dx[i], y+dy[i])) {
                    q.push(make_pair(make_pair(x+dx[i], y+dx[i]), time+1));
                    visit[x+dx[i]][y+dx[i]] = true;
            }
        }
    }
}

// check if there are fishes that shark can eat
bool check() { // return true if there is.
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            if(arr[i][j] > 0 && arr[i][j] < shark) return true;
        }
    }
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9) loc_of_shark = make_pair(i, j);
        }
    }

    /* solving */
    while(check()){
        loc_of_shark = bfs(loc_of_shark);
    }

    /* output */
    cout << result << '\n';
}