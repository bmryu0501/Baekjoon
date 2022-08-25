#include <iostream>

int main() {
    int N, a, b;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d%d", &a, &b);
        printf("Case #%d: %d\n", i, a+b);
    }
}