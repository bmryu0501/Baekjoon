#include <iostream>

using namespace std;

long long A, B, C;

long long f(long long a, long long b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    return ((f((a*a)%C, b/2))%C * (b%2?(a%C):1))%C;
}

int main() {
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld", f(A, B)%C);
}