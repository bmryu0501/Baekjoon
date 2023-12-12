#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 5000
#define MAX_K 1000000000

using namespace std;

int N, Q;
int usado[MAX_N+1][MAX_N+1];
bool updated[MAX_N+1];
bool visited[MAX_N+1];

vector<int> v[MAX_N+1];

void dfs(int start, int now, int score) {
    visited[now] = true;
    for(int i=0;i<v[now].size();i++) {
        if(visited[v[now][i]]) continue;
        usado[start][v[now][i]] = min(score, usado[now][v[now][i]]);
        dfs(start, v[now][i], usado[start][v[now][i]]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    int p, q, r;
    for(int i=0;i<N-1;i++) {
        cin >> p >> q >> r;
        usado[p][q] = r;
        usado[q][p] = r;
        v[p].push_back(q);
        v[q].push_back(p);
    }

    int k, v;
    while(Q--) {
        int count = 0;
        cin >> k >> v;
        if(!updated[v]) {
            memset(visited, 0, sizeof(visited));
            dfs(v, v, MAX_K);
            updated[v] = true;
        }
        for(int i=1;i<=N;++i) if(usado[v][i] >= k) count++;
        cout << count << '\n';
    }

    // for(int i=1;i<=N;i++) {
    //     for(int j=1;j<=N;j++) cout << usado[i][j] << ' ';
    //     cout << '\n';
    // }

    return 0;
}