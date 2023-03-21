/***************************************************
 * 2667 단지번호 붙이기
 * 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색
****************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

/* condition */
#define MAX_N 25

/* variables */
int N, village=0;
bool arr[MAX_N][MAX_N];
int house[MAX_N*MAX_N];
char line[MAX_N+1];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/* functions */
void dfs(int y, int x) {
    house[village]++;
    arr[y][x]=0;

    int cy, cx;
    for(int d=0;d<4;d++) {
        cy = y+dy[d];
        cx = x+dx[d];
        if(cy>=0&&cy<N&&cx>=0&&cx<N&&arr[cy][cx]) dfs(cy, cx);
    }
}


int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /* input */
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> line;
        for(int j=0;j<N;j++) {
            arr[i][j] = line[j]-'0';
        }
    }

    /* solving */
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) {
        if(arr[i][j]) {
            dfs(i, j);
            village++;
        }
    }

    /* output */
    cout << village << '\n';
    sort(house, house+village);
    for(int i=0;i<village;i++) cout << house[i] << '\n';
}