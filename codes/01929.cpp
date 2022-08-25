#include <iostream>

using namespace std;

/* �Լ� */
// 3 �̻��� Ȧ�� num�� ���Ͽ� �Ҽ����� �Ǻ�
bool isPrimeNum(int num) {
    for(int i = 3; i * i <= num; i += 2) { // ��num ������ Ȯ��
        if(num % i == 0) return false; // �Ҽ��� �ƴ� ��� false ��ȯ
    }
    return true; // �Ҽ��� ��� true ��ȯ
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