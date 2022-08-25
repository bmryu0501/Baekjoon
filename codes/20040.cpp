#include <iostream>

using namespace std;

const int MAXN = 5e5, MAXM = 1e6;

int N, M, parent[MAXN];

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    parent[find(b)] = find(a);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) parent[i] = i;
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(find(a) == find(b)) {
            printf("%d", i+1);
            return 0;
        }
        merge(a, b);
    }

    printf("0");
}