#include <iostream>

using namespace std;

int decompSum(int num) { // decomposition sum
    if(num >= 10) return decompSum(num/10) + num%10;
    return num;
}

int main() {
    int N, M = 0;

    scanf("%d", &N);

    for(int i = 1; i < N; i++) {
        if(i + decompSum(i) == N) {
            M = i;
            break;
        }
    }

    printf("%d\n", M);
}