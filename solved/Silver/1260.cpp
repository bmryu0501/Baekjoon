#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1000, MAXM = 10000;

int N, M, V;
int adj_matrix[MAXN+1][MAXN+1];
int visited[MAXN+1];
queue<int> q;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for(int i = 1; i < N + 1; i++)
        if(adj_matrix[v][i] && !visited[i]) dfs(i);
}

void bfs(int v) {
    visited[v] = 1;
    q.push(v);

    while(!q.empty()) {
        v = q.front();
        printf("%d ", v);
        q.pop();

        for(int i = 1; i < N + 1; i++) {
            if(adj_matrix[v][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}



int main() {
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }

    dfs(V);
    printf("\n");
    for(int i = 1; i < N + 1; i++) visited[i] = 0;
    bfs(V);
}