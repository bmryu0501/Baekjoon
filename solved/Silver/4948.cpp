#include <iostream>

using namespace std;

/* 함수 */
// 3 이상의 홀수 num에 대하여 소수인지 판별
bool isPrimeNum(int num) {
    for(int i = 3; i * i <= num; i += 2) { // √num 까지만 확인
        if(num % i == 0) return false; // 소수가 아닌 경우 false 반환
    }
    return true; // 소수인 경우 true 반환
}

int main() {
    int n, cnt;

    scanf("%d", &n);

    while(n != 0) {
        cnt = 0;

        if(n == 1) n++;
        
        if(n % 2 == 0) {
            for (int i = n + 1; i < n * 2; i += 2)
                if(isPrimeNum(i)) cnt++;
        } else {
            for (int i = n + 2; i < n * 2; i += 2)
                if(isPrimeNum(i)) cnt++;
        }

        printf("%d\n", cnt);

        scanf("%d", &n);
    }
}