#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 65

int arr[MAX_N][MAX_N];

int getValue(int i, int j) {
    return arr[i][j] - arr[i-1][j] - arr[i][j-1] + arr[i-1][j-1];
}

void check(int N, int i, int j) {
    int val = arr[i-1+N][j-1+N] - arr[i-1][j-1+N] - arr[i-1+N][j-1] + arr[i-1][j-1];
    if(val > 0 && val < N*N) {
        printf("(");
        check(N/2, i, j);
        check(N/2, i, j+(N/2));
        check(N/2, i+(N/2), j);
        check(N/2, i+(N/2), j+(N/2));
        printf(")");
    } else {
        printf("%d", val?1:0);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char line[MAX_N];
    for(int i=1;i<=N;++i){
        scanf("%s", line);
        for(int j=1;j<=N;++j) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + line[j-1] - '0';
        }
    }

    // for(int i=0;i<=N;++i) {
    //     for(int j=0;j<=N;++j) printf("%2d ", arr[i][j]);
    //     printf("\n");
    // }
    // printf("\n");

    check(N, 1, 1);

    return 0;
}