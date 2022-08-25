#include <iostream>

int main() {
    int N;

    scanf("%d", &N);

    int i = 2;

    while(N > 1) {
        if(N % i == 0) {
            printf("%d\n", i);
            N /= i;
        } else i++;
    }
}