#include <iostream>
#include <map>

using namespace std;

const int MAXV = 1e4;
int V, E, parent[MAXV+1], cnt = 0, result = 0;
multimap<int, pair<int, int>> m;

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    parent[find(b)] = find(a);
}

int main() {
    scanf("%d %d", &V, &E);
    for(int i = 1; i < E + 1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        m.insert({c, {a, b}});
    }

    for(int i = 0; i < MAXV + 2; i++) parent[i] = i;

    multimap<int, pair<int, int>>::iterator it;

    for(it = m.begin(); cnt < V - 1; it++) {
        int a = (*it).second.first;
        int b = (*it).second.second;
        if(find(a) != find(b)) {
            cnt++;
            result += (*it).first;
            merge(a, b);
        }
    }

    printf("%d", result);
}