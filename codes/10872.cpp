#include <iostream>

using namespace std;

int fact(int num) {
    if(num == 1 || num == 0) return 1;
    else return fact(num - 1) * num;
}

int main() {
    int N;

    scanf("%d", &N);

    printf("%d\n", fact(N));
}