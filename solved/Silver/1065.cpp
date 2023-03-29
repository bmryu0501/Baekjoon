#include <iostream>

int diff(int n) {
    return (n/10)%10 - n%10;
}

bool check(int i) {
    int difference = diff(i);
    while(i > 99) {
        i /= 10;
        if(diff(i) != difference) return false;
    }
    return true;
}

int main() {
    int N, cnt;
    cnt = 0;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        if(check(i)) cnt++;
    }

    printf("%d\n", cnt);
}