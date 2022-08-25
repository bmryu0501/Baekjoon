#include <iostream>

using namespace std;

bool isPrimeNum(int num) {
    if(num == 1) return false;
    if(num == 2 || num == 3) return true;
    if(num % 2 == 0) return false;

    for(int i = 2; i * i <= num; i += 2) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    int N, num, cnt = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &num);
        if(isPrimeNum(num)) cnt++;
    }

    printf("%d\n", cnt);
}