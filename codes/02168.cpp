#include <iostream>

// 서로수 일 때 (가로) + (세로) - 1
// 서로수가 아닐 때 (가로) + (세로) - (최대 공약수)

using namespace std;

int x, y;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    scanf("%d%d", &x, &y);
    printf("%d", x + y - gcd(x, y));
}