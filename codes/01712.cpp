#include <iostream>

using namespace std;

int main() {
    int A, B, C, cnt;
    scanf("%d%d%d", &A, &B, &C);

    if(B >= C) {
        printf("%d", -1);
        return 0;
    }

    cnt = A / (C - B);

    printf("%d\n", ++cnt);
}