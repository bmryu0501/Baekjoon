/*
2048 (Easy)
https://www.acmicpc.net/problem/12100
*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 20
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int N;
int answer;
int board[MAX_N][MAX_N];
bool isMerged[MAX_N][MAX_N];

void dfs(int level, int dir, int maxNum) {
    if(level > 5) {
        answer = max(answer, maxNum);
        return;
    }

    memset(isMerged, 0, sizeof(isMerged));

    
}

int main() {
    int arr[MAX_N][MAX_N] = {0, };

    cin >> N;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin >> arr[i][j];

    dfs(0, 0, 0);

    cout << answer;

    return 0;
}