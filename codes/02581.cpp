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
    /* 변수 정의 */
    // sum: M, N 사이의 소수들의 합
    // min: 소수들 중 가장 작은 수
    int M, N, sum = 0, min = 0;

    scanf("%d%d", &M, &N);


    /* 과정 */
    // N = 1인 경우: 소수가 없음
    if(N == 1) {
        printf("%d\n", -1);
        return 0;
    }

    // M = 1인 경우 M = 2
    if(M == 1) M ++;

    // M = 2인 경우
    if(M == 2) {
        sum += M;
        min = M;
        M++; // M = 3
    }

    // M이 짝수일 경우 홀수로 만들어 줌
    if(M % 2 == 0) M++;

    // 짝수는 넘어가는 loop (M > 3인 홀수이어야 함)
    for(int i = M; i <= N; i += 2) { // M과 N 사이의 모든 홀수를 대상으로
        if(isPrimeNum(i)) { // 소수인 경우
            sum += i; // sum에 더해줌
            if(min == 0) min = i; // 최솟값이 아직 없다면 채워줌
        }
    }


    /* 결과 출력 단계 */
    // sum = 0이면 소수가 없는 경우
    // -1을 출력하고 종료
    if(sum == 0) {
        printf("%d\n", -1);
        return 0;
    }

    // 아니면 첫째 줄에 소수들의 합을, 둘째 줄에 그 중 최솟값을 출력
    printf("%d\n%d\n", sum, min);
}