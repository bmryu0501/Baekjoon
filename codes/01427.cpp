#include <iostream>

using namespace std;

int main() {
    int N, num[10] = {0, };

    scanf("%d", &N);

    while(N > 0) {
        num[N%10]++;
        N /= 10;
    }

    for(int i = 10; i-- > 0;) {
        while(num[i]-- > 0)
            printf("%d", i);
    }
}