#include <iostream>
#include <algorithm>
using namespace std;

/*
1. 나이 만큼 양분을 먹고 나이++
    * 어린 나무 먼저
    * 못먹으면 죽는다
2. 죽은 나무들이 양분으로 변함 (나이 / 2)
3. 인접 8칸에 5의 배수 나이 나무 번식
4. A[r][c]를 각 칸에 추가
*/

#define MAX_N 10
#define MAX_M MAX_N * MAX_N
#define MAX_K 1000

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Tree{
    int size;
    int tree[MAX_K];
} trees[MAX_N+1][MAX_N+1], dead[MAX_N+1][MAX_N+1];

int N, M, K;
int answer;
int A[MAX_N+1][MAX_N+1];
int ground[MAX_N+1][MAX_N+1];

bool isValid(int y, int x) {
    if(y <= 0 || y > N || x <= 0 || x > N) return false;
    return true;
}

void spring() {
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++) {
        Tree* now = &trees[i][j];
        if(now->size > 1) sort(now->tree, now->tree + now->size);

        int cnt_trees = now->size;
        for(int k=0;k<cnt_trees;k++) {
            if(now->tree[k] <= ground[i][j]){
                ground[i][j] -= now->tree[k]++;
            }
            else {
                dead[i][j].tree[dead[i][j].size++] = now->tree[k];
                now->tree[k] = 0;
                now->size--;
            }
        }
    }
}

void summer() {
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++) {
        while(dead[i][j].size-- >= 0) {
            ground[i][j] += dead[i][j].tree[dead[i][j].size];
        }
        dead[i][j].size = 0;
    }
}

void fall() {
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++) {
        Tree* now = &trees[i][j];
        for(int k=0;k<now->size;k++) {
            if(now->tree[k] % 5 == 0) {
                for(int d=0;d<8;d++) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if(!isValid(ny, nx)) continue;

                    trees[ny][nx].tree[trees[ny][nx].size++] = 1;
                }
            }
        }
    }
}

void winter() {
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++) {
        ground[i][j] += A[i][j];
    }
}

int main() {
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) {
        cin >> A[i][j];
        ground[i][j] = A[i][j];
    }

    int y, x;
    Tree now;
    for(int i=0;i<M;i++) {
        cin >> y >> x;
        cin >> trees[y][x].tree[trees[y][x].size++];
    }

    while(K--) {
        spring();
        summer();
        fall();
        winter();
    }
    
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++) answer += trees[i][j].size;
    cout << answer << "\n";
    
    return 0;
}
