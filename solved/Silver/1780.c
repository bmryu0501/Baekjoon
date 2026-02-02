#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 2188

int arr[MAX_N][MAX_N];
int count[3];

int check(int size, int y, int x, int target) {
    for(int i=0;i<size;++i) for(int j=0;j<size;++j) {
        if(arr[y+i][x+j] != target) return 0;
    }

    return 1;
}

void go(int size, int y, int x) {
    int target = arr[y][x];

    if(check(size, y, x, target)) {
        count[target+1]++;
    } else {
        int n = size/3;
        go(n, y, x);
        go(n, y, x+n);
        go(n, y, x+n+n);
        go(n, y+n, x);
        go(n, y+n, x+n);
        go(n, y+n, x+n+n);
        go(n, y+n+n, x);
        go(n, y+n+n, x+n);
        go(n, y+n+n, x+n+n);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;++i) for(int j=0;j<N;++j) {
        scanf("%d", &arr[i][j]);
    }

    go(N, 0, 0);

    // printf("\n");
    // for(int i=0;i<N;++i) {
    //     for(int j=0;j<N;++j) printf("%d ", arr[i][j]+1);
    //     printf("\n");
    // }

    for(int i=0;i<3;++i) printf("%d\n", count[i]);

    return 0;
}