#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_V 20000
#define MAX_E 300000

struct Edge {
    int from, to;
    int cost;

    bool operator < (Edge e) const {
        return cost > e.cost;
    }
};

int V, E;
vector<Edge> nodes[MAX_V+1];

int main() {
    int start;
    cin >> V >> E >> start;

    int from, to, cost;
    for(int i=0;i<E;i++) {
        cin >> from >> to >> cost;
        nodes[from].push_back({from, to, cost});
    }

    for(int i=1;i<=V;i++) {
        priority_queue<Edge> q;

        


    }

    return 0;
}