#include <iostream>

using namespace std;

int main() {
    int T, H, W, N; // �Է����� �־��� ������
    int X, Y; // Y: ��, X: ȣ��

    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d%d%d", &H, &W, &N);
        Y = N % H == 0? H : N % H;
        X = N % H == 0? N / H : N / H + 1;
        printf("%d%02d\n", Y, X);
    }
}