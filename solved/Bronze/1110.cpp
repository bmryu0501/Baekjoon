#include <iostream>

using namespace std;

int main() {
    int N, M, cnt;
    cnt = 0;
    scanf("%d", &N);
    M = N;
    do {
        M = ((M%10)*10) + ((M/10) + (M%10))%10;
        cnt++;
    } while (N != M);
    printf("%d\n", cnt);
}