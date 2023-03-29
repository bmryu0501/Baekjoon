#include <iostream>

using namespace std;

bool is666(int num) {
    while(num > 665) {
        if(num % 1000 == 666)
            return true;
        num /= 10;
    }
    return false;
}


int main() {
    int N, ans = 666;

    scanf("%d", &N);

    for(int cnt = 0; cnt < N; ans++) {
        if(is666(ans)) cnt++;
    }

    ans--;

    printf("%d\n", ans);
}