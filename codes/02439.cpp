#include <iostream>

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        for(int j = N; j > i; j--)
            printf(" ");
        for(int j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
}