#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N 100000
#define MAX_K 100000

struct Position{
    int x;
    int count;
};

int N, K;
queue<Position> q;
bool visited[MAX_K+1];

/* functions */
int bfs(int start) {
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty()) {
        Position now = q.front();
        q.pop();

        if(now.x == K) return now.count;
        
        Position way[3] = {{now.x-1, now.count+1},
                            {now.x+1, now.count+1},
                            {now.x*2, now.count+1}};
 
        for(int i=0;i<3;i++) {
            Position next = way[i];
            if(next.x < 0 || next.x > MAX_K || visited[next.x]) continue;
            q.push(next);
            visited[next.x] = true;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    memset(visited, 0, sizeof(visited));

    cin >> N >> K;

    cout << bfs(N);
}