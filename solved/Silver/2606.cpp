#include <iostream>
#include <queue>

using namespace std;

#define MAX_N (105)
#define MAX_M (MAX_N * MAX_N)

int N, M;
int arr[MAX_N][MAX_N] = {0};
bool visited[MAX_N] = {0};

queue<int> q;

int main() {
    cin >> N >> M;
    int a, b;
    for(int i=0;i<M;++i) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    q.push(1);
    visited[1] = true;
    int now;
    while(!q.empty()) {
        now = q.front();
        q.pop();

        for(int i=1;i<=N;++i) {
            if(arr[now][i] == false || visited[i]) continue;
            q.push(i);
            visited[i] = true;
        }
    }

    int ans = 0;
    for(int i=2;i<=N;++i) ans += visited[i] ? 1 : 0;

    cout << ans;

    return 0;
}