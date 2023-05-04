#include <iostream>
using namespace std;

#define MAX_N 50
#define MAX_M 50

int N, M;
int parent[MAX_N+1];
int party[MAX_M][MAX_N+1];

int main() {
    cin >> N >> M;
    for(int i=1;i<=N;i++) parent[i] = i;

    int n, fact, id;
    cin >> n;
    cin >> fact;
    while(--n) {
        cin >> id;
        parent[id] = fact;
    }

    int t;
    for(int i=0;i<M;i++) {
        bool check = false;
        cin >> t;
        party[i][0] = t;
        for(int j=1;j<=t;j++) {
            cin >> party[i][j];
            if(parent[party[i][j]] == fact) check = true;
        }
        if(check) for(int j=1;j<=t;j++) {
            parent[party[i][j]] = fact;
        }
    }

    int cnt = 0;
    for(int i=0;i<M;i++) {
        if(party[i][1] != fact) cnt++;
    }

    cout << cnt;

    return 0;
}