/*
9205 맥주 마시면서 걸어가기
https://www.acmicpc.net/problem/9205
*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 103

struct Node {
    int x, y;
    bool visited;
};

int T, N;
Node convs[MAX_N];

void init() {
    memset(convs, 0, sizeof(convs));
}

int getDist(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool move(int idx) {
    if(idx == N+1) return true;

    convs[idx].visited = true;

    for(int i=N+1;i>0;i--) {
        if(convs[i].visited) continue;
        int dist = getDist(convs[idx], convs[i]);
        if(dist > 1000) continue;

        if(move(i)) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        init();
        cin >> N;

        for(int i=0;i<N+2;i++)
            cin >> convs[i].x >> convs[i].y;
        
        if(move(0)) cout << "happy\n";
        else cout << "sad\n";
    }

    return 0;
}