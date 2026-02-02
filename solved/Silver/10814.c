#include <stdio.h>
#include <string.h>

#define MAX_N 100004
#define MAX_LEN 102

typedef struct {
    int age;
    char name[MAX_LEN];
} Data;

int N;
Data arr[MAX_N];
Data sorted[MAX_N];

void merge(int, int, int);
void mSort(int, int);

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;++i) {
        scanf("%d %s", &arr[i].age, &arr[i].name);
    }

    mSort(0, N-1);

    for(int i=0;i<N;++i) {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }

    return 0;
}

void merge(int left, int mid, int right) {
    int l, r, idx;
    l = left;
    r = mid+1;
    idx = left;

    while(l <= mid && r <= right) {
        if(arr[l].age <= arr[r].age) {
            sorted[idx++] = arr[l++];
        } else {
            sorted[idx++] = arr[r++];
        }
    }

    for(int i=l;i<=mid;++i) {
        sorted[idx++] =arr[l++];
    }
    for(int i=r;i<=right;++i) {
        sorted[idx++] = arr[r++];
    }

    memcpy(&arr[left], &sorted[left], sizeof(Data)*(right-left+1));

    return;
}

void mSort(int left, int right) {
    int mid;

    if(left < right) {
        mid = (left + right) / 2;
        mSort(left, mid);
        mSort(mid+1, right);
        merge(left, mid, right);
    }

    return;
}