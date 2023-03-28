#include <iostream>
#include <queue>

#define MAX_N 2001

using namespace std;

struct Node {
    int x, y;
};

struct Edge {
    int a, b;
    int cost;

    bool operator < (Edge e) const {
        return cost > e.cost;
    }
};

int N, C;
Node arr[MAX_N];
priority_queue<Edge> q;
int parent[MAX_N];

int getCost(Node a, Node b) {
    return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}

int Find(int a) {
    if(parent[a] == a) return a;
    return Find(parent[a]);
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);

    if(pa == pb) return;

    parent[pb] = pa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    int x, y;
    for(int i=0;i<N;i++) cin >> arr[i].x >> arr[i].y;

    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        int cost = getCost(arr[i], arr[j]);
        if(cost >= C) q.push({i, j, cost});
    }

    if(q.size() < N-1) {
        cout << -1;
        return 0;
    }

    for(int i=0;i<N;i++) parent[i] = i;

    Edge now;
    int edges = 0;
    int answer = 0;
    while(!q.empty()) {
        if(edges == N-1) break;
        now = q.top(); q.pop();
        if(Find(now.a) == Find(now.b)) continue;
        Union(now.a, now.b);
        edges++;
        answer += now.cost;
    }

    if(edges < N-1) cout << -1;
    else cout << answer;

    return 0;
}