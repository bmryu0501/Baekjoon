#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_N 500005
#define MAX_M 500005

int N, M;
int cards[MAX_N];
int arr[MAX_M];

int compareInt(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai - bi;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i) {
        scanf("%d", &cards[i]);
    }

    qsort(cards, N, sizeof(int), compareInt);

    int t;
    scanf("%d", &M);
    for(int i=0;i<M;++i) {
        scanf("%d", &t);
        printf("%d ", bsearch(&t, cards, N, sizeof(int), compareInt)==NULL?0:1);
    }

    return 0;
}