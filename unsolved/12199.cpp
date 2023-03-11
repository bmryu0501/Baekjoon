/*
2048 (Easy)
https://www.acmicpc.net/problem/12100
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX_N 20
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int N;
int answer;

void dfs(int level, int arr[MAX_N][MAX_N], int max_num) {

    int new_arr[MAX_N][MAX_N];


    queue<int> q;

    // 왼쪽으로 밀었을 때
    memset(new_arr, 0, sizeof(new_arr));
    int now = 0;
    int idx = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j]) q.push(arr[i][j]);
        }
        while(!q.empty()) {
            if(!now) {
                now = q.front(); q.pop();
            } else {
                if(now == q.front()) {
                    q.pop();
                    now *= 2;
                }
                arr[i][idx++] = now;
                now = 0;
            }
        }
        if(now) new_arr[i][idx] = now;
    }

    // 오른쪽으로 밀었을 때
    memset(new_arr, 0, sizeof(new_arr));
    now = 0;
    idx = N-1;
    for(int i=0;i<N;i++) {
        for(int j=N-1;j>=0;j--) {
            if(arr[i][j]) q.push(arr[i][j]);
        }
        while(!q.empty()) {
            if(!now) {
                now = q.front(); q.pop();
            } else {
                if(now == q.front()) {
                    q.pop();
                    now *= 2;
                }
                arr[i][idx++] = now;
                now = 0;
            }
        }
        if(now) new_arr[i][idx] = now;
    }
}

int main() {
    int arr[MAX_N][MAX_N] = {0, };

    cin >> N;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin >> arr[i][j];

    dfs(0, arr, 2);

    cout << answer;

    return 0;
}