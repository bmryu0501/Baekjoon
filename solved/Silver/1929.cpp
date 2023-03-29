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
    int M, N;

    scanf("%d%d", &M, &N);

    if(M == 1) M++;

    if(M == 2 && N > 1) {
        printf("%d\n", 2);
        M += 1;
    }

    if(M % 2 == 0) M++;

    for (int i = M; i <= N; i += 2) {
        if(isPrimeNum(i)) printf("%d\n", i);
    }
}