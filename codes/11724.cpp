#include <iostream>

using namespace std;

const int MAXN = 1000;
int N, M, cnt = 0, arr[MAXN + 1][MAXN+ 1], visited[MAXN+1];
 
void dfs(int v) {
    visited[v] = 1;
    for(int i = 1; i < N + 1; i++)
        if(arr[v][i] && !visited[i]) dfs(i);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int i = 1; i < N + 1; i++) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }

    printf("%d", cnt);
}