#include <iostream>

using namespace std;

const int MAXN = 1024;
int N, M, num, sum[MAXN+1][MAXN+1];
int x1, y1, x2, y2;

int main() {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
           scanf("%d", &num);
           sum[i+1][j+1] = num + sum[i][j+1] + sum[i+1][j] - sum[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
    }
}