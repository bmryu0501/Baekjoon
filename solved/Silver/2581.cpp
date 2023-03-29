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
    /* ���� ���� */
    // sum: M, N ������ �Ҽ����� ��
    // min: �Ҽ��� �� ���� ���� ��
    int M, N, sum = 0, min = 0;

    scanf("%d%d", &M, &N);


    /* ���� */
    // N = 1�� ���: �Ҽ��� ����
    if(N == 1) {
        printf("%d\n", -1);
        return 0;
    }

    // M = 1�� ��� M = 2
    if(M == 1) M ++;

    // M = 2�� ���
    if(M == 2) {
        sum += M;
        min = M;
        M++; // M = 3
    }

    // M�� ¦���� ��� Ȧ���� ����� ��
    if(M % 2 == 0) M++;

    // ¦���� �Ѿ�� loop (M > 3�� Ȧ���̾�� ��)
    for(int i = M; i <= N; i += 2) { // M�� N ������ ��� Ȧ���� �������
        if(isPrimeNum(i)) { // �Ҽ��� ���
            sum += i; // sum�� ������
            if(min == 0) min = i; // �ּڰ��� ���� ���ٸ� ä����
        }
    }


    /* ��� ��� �ܰ� */
    // sum = 0�̸� �Ҽ��� ���� ���
    // -1�� ����ϰ� ����
    if(sum == 0) {
        printf("%d\n", -1);
        return 0;
    }

    // �ƴϸ� ù° �ٿ� �Ҽ����� ����, ��° �ٿ� �� �� �ּڰ��� ���
    printf("%d\n%d\n", sum, min);
}