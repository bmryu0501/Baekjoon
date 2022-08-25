#include <iostream>

using namespace std;

int fibo(int num) {
    if(num == 1 || num == 2) return 1;
    else if(num < 0) return 0;
    else return fibo(num - 2) + fibo(num - 1);
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%d\n", fibo(n));
}