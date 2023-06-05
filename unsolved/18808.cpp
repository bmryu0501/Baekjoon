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

bool check(int idx) {
    Block* now = &blocks[idx];

    //TODO
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
        for(int d=0;d<4;d++) {
            if(check(k)) {
                ans += blocks[k].num;
                break;
            }
            rotate(k);
        }
    }

    cout << ans;

    return 0;
}