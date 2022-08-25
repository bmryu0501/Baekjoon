#include <iostream>

using namespace std;

int main() {
    int T, H, W, N; // 입력으로 주어진 변수들
    int X, Y; // Y: 층, X: 호수

    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d%d%d", &H, &W, &N);
        Y = N % H == 0? H : N % H;
        X = N % H == 0? N / H : N / H + 1;
        printf("%d%02d\n", Y, X);
    }
}