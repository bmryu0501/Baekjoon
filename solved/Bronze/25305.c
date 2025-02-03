#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1004

int N, k;
int arr[MAX_N];

int compare(const void*, const void*);

int main() {
    scanf("%d %d", &N, &k);
    for(int i=0;i<N;++i) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    printf("%d", arr[k-1]);

    return 0;
}

int compare(const void* p1, const void* p2) {
    int a = *(int*)p1;
    int b = *(int*)p2;

    return b - a;
}