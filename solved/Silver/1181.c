#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20005
#define MAX_LEN 52

int N;
char arr[MAX_N][MAX_LEN];

int compare(const void* str1, const void* str2) {
    char* s1 = (char*) str1;
    char* s2 = (char*) str2;

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    if(l1 == l2) {
        for(int i=0;i<l1;++i) {
            if(s1[i] != s2[i]) return s1[i] - s2[i];
        }
    }

    return l1 - l2;
}

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;++i) {
        scanf("%s", &arr[i]);
    }

    qsort(arr, N, sizeof(char)*MAX_LEN, compare);

    char prev[MAX_N];
    strcpy(prev, arr[0]);
    printf("%s\n", arr[0]);
    for(int i=1;i<N;++i) {
        if(strcmp(prev, arr[i]) == 0) continue;
        strcpy(prev, arr[i]);
        printf("%s\n", arr[i]);
    }
}