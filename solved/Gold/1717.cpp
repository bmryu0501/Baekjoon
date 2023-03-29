#include <iostream>

using namespace std;

const int MAXN = 1e6, MAXM = 1e5;

int N, M, parent[MAXN+1];

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    parent[find(b)] = find(a);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N + 1; i++)
        parent[i] = i;
    for(int i = 0; i < M; i++) {
        int op, a , b;
        scanf("%d %d %d", &op, &a, &b);
        if(op == 0) merge(a, b);
        else find(a)==find(b)?printf("YES\n"):printf("NO\n");
    }
}