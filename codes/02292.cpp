#include <iostream>

using namespace std;

int main() {
    int N, floor, sum = 1;

    scanf("%d", &N);

    if(N == 1) {
        printf("%d", 1);
        return 0;
    }

    for(floor = 1; sum < N; floor++) {
        sum += (floor - 1) * 6;
    }

    printf("%d\n", floor - 1);
}