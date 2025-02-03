#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1004

int N;
int arr[MAX_N];

int icompare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return num1-num2;
}

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;++i) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), icompare);

    for(int i=0;i<N;++i) printf("%d\n", arr[i]);

    return 0;
}