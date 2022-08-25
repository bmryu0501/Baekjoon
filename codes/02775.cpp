#include <iostream>

using namespace std;

int sum(int k, int n) {
    if(k == 0) {
        return n;
    }
    if(n == 1) {
        return 1;
    }
    return sum(k - 1, n) + sum(k, n - 1);
}

int main() {
    int T, k, n;

    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d%d", &k, &n);
        printf("%d\n", sum(k, n));
    }
}