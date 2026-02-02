#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20004

int main() {
    int N, K;
    int cnt = 0;
    char str[MAX_N];
    scanf("%d %d", &N, &K);
    scanf("%s", str);

    for(int i=0;i<N;++i) {
        if(str[i] == 'P') for(int j=i-K;j<=K&&j<N;++j) {
        }
    }

    printf("%d", cnt);

    return 0;
}