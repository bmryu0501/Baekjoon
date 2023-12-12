/*
5972번 택배 배송

다익스트라
메모리 초과
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//#define DEBUG

#define MAX_N 50000
#define MAX_M 50000

struct Edge{
    int from, to, cost, cnt;

    Edge(int from, int to, int cost, int cnt) : from(from), to(to), cost(cost), cnt(cnt) {}

    bool operator<(const Edge& E) const {
        return cost > E.cost;
    }
};

int N, M;
int A, B, C;
vector<vector<Edge>> edges;

int main() {
    #ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif

    cin >> N >> M;

    edges.resize(N+1);

    for(int i=0;i<M;i++) {
        cin >> A >> B >> C;
        edges[A].push_back({A, B, C+1, 0});
        edges[B].push_back({B, A, C+1, 0});
    }

    priority_queue<Edge> pq;
    pq.emplace(1, 1, 0, 0);

    Edge now(1, 1, 0, 0);
    while(true) {
        now = pq.top();
        pq.pop();

        #ifdef DEBUG
        cout << "{" << now.from << ", " << now.to << ", " << now.cost << ", " << now.cnt << "}\n";
        char c;
        cin >> c;
        #endif

        if(now.to == N) break;

        for(int i=0;i<edges[now.to].size();i++) {
            Edge* next = &edges[now.to][i];
            pq.emplace(next->from, next->to, now.cost + next->cost, now.cnt+1);
        }
    }

    cout << now.cost - now.cnt;

    return 0;
}