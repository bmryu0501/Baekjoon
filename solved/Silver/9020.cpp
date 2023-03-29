#include <iostream>

using namespace std;

/* 함수 */
// 2 이상의 num에 대하여 소수인지 판별
bool isPrimeNum(int num) {
    if(num == 2) return true; // 2는 true
    if(num % 2 == 0) return false; // 짝수는 false
    for(int i = 3; i * i <= num; i += 2) { // √num 까지 모든 홀수로 나눠봄
        if(num % i == 0) return false; // 소수가 아닌 경우 false 반환
    }
    return true; // 소수인 경우 true 반환
}

int main() {
    // T: test case
    // n: 입력되는 n
    // ans: 골드바흐 수 중 작은 수
    int T, n, ans;

    scanf("%d", &T);

    for(int t = 0; t < T; t++) {
        scanf("%d", &n);

        for(int i = 2; i + i <= n; i++) { // 2부터 n/2까지
            // i와 n-i가 모두 소수인 경우 ans 업데이트
            if(isPrimeNum(i) && isPrimeNum(n - i)) ans = i;
        }

        printf("%d %d\n", ans, n - ans);
    }
}