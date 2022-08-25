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