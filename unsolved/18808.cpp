/*
백준 18808번 스티커 붙이기
https://www.acmicpc.net/problem/18808
*/

#define DEBUG

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 40
#define MAX_M 40
#define MAX_K 100
#define MAX_RC 10

struct Block{
    int R, C;
    int num;
    bool shape[MAX_RC][MAX_RC];
};  

int N, M, K, ans;
Block blocks[MAX_K];
bool notebook[MAX_N][MAX_M];

void init() {
    memset(blocks, 0, sizeof(blocks));
    memset(notebook, 0, sizeof(notebook));
    ans = 0;
}

void rotate(int idx){
    Block* now = &blocks[idx];

    // rotate
    Block temp = {0, };
    temp.R = now->C;
    temp.C = now->R;
    for(int i=0;i<now->R;i++)for(int j=0;j<now->C;j++) temp.shape[j][now->R-i-1] = now->shape[i][j];

    // copy
    for(int i=0;i<temp.R;i++)for(int j=0;j<temp.C;j++) now->shape[i][j] = temp.shape[i][j];
    now->R = temp.R;
    now->C = temp.C;
}

bool isAvailable(int r, int c, Block* now) {
    for(int i=0;i<now->R;i++)for(int j=0;j<now->C;j++) {
        if(r+now->R >= N || c+now->C >= N) continue; // 스티커를 온전히 못붙인다
        if(notebook[r+i][c+j] && now->shape[i][j]) // 둘 다 1 (스티커를 붙일 수 없다)
            continue;
        return true;
    }
    return false;
}

bool check(int idx) {
    Block* now = &blocks[idx];

    for(int i=0;i<N;i++)for(int j=0;j<M;j++) {
        if(notebook[i][j]) continue; // 이미 스티커 붙은 곳
        if(isAvailable(i, j, now)) { // (i, j)에 붙일 수 있으면
            // 붙인다
            for(int r=0;r<now->R;r++)for(int c=0;c<now->C;c++) notebook[i+r][j+c] = now->shape[r][c];
            return true;
        }
    }
}

int main() {
    FASTIO;
    init();

    // input
    cin >> N >> M >> K;
    for(int k=0;k<K;k++) {
        Block* now = &blocks[k];
        cin >> now->R >> now->C;
        for(int i=0;i<now->R;i++)for(int j=0;j<now->C;j++) {
            cin >> now->shape[i][j];
            if(now->shape[i][j]) now->num++;
        }
    }

    // solve
    for(int k=0;k<K;k++) {
        for(int d=0;d<4;d++) { // 4 방향에 대하여
            if(check(k)) { // 붙일 수 있으면
                ans += blocks[k].num;
                break; // 끝냄
            }
            // 못붙이면 돌린다
            rotate(k);
        }
    }

    #ifdef DEBUG
    cout << "\n";
    for(int k=0;k<K;k++) {
        Block* now = &blocks[k];
        for(int i=0;i<now->R;i++) {
            for(int j=0;j<now->C;j++) cout << now->shape[i][j] << ' ';
            cout << "\n";
        }
        cout << "\n";
    }

    cout << "\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) cout << notebook[i][j] << " ";
        cout << "\n";
    }
    #endif

    cout << ans;

    return 0;
}