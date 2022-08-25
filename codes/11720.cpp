#include <iostream>

using namespace std;

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    char str[N];
    scanf("%s", &str);
    for(int i = 0; i < N; i++) {
        sum += str[i] - '0';
    }

    printf("%d\n", sum);
}