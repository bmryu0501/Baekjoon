#include <iostream>

using namespace std;

int main() {
    int N, x[50], y[50], rank[50] = {0, };

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(x[i] < x[j] && y[i] < y[j]) rank[i]++;
        }
    }

    for(int i = 0; i < N; i++) {
        printf("%d ", rank[i]+1);
    }
    printf("\n");
}