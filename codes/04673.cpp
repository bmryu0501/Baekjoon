#include <iostream>

void selfNum(bool a[], int n) {
    int sum = n;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    if(sum > 10000 || a[sum] == true) return;
    a[sum] = true;
    selfNum(a, sum);
}

int main() {
    bool a[10001] = {false, };

    for(int i = 0; i < 10001; i++) {
        selfNum(a, i);
    }

    for(int i = 0; i < 10001; i++) {
        if(a[i] == false) printf("%d\n", i);
    }
}