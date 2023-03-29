#include <iostream>

using namespace std;

/* �Լ� */
// 2 �̻��� num�� ���Ͽ� �Ҽ����� �Ǻ�
bool isPrimeNum(int num) {
    if(num == 2) return true; // 2�� true
    if(num % 2 == 0) return false; // ¦���� false
    for(int i = 3; i * i <= num; i += 2) { // ��num ���� ��� Ȧ���� ������
        if(num % i == 0) return false; // �Ҽ��� �ƴ� ��� false ��ȯ
    }
    return true; // �Ҽ��� ��� true ��ȯ
}

int main() {
    // T: test case
    // n: �ԷµǴ� n
    // ans: ������ �� �� ���� ��
    int T, n, ans;

    scanf("%d", &T);

    for(int t = 0; t < T; t++) {
        scanf("%d", &n);

        for(int i = 2; i + i <= n; i++) { // 2���� n/2����
            // i�� n-i�� ��� �Ҽ��� ��� ans ������Ʈ
            if(isPrimeNum(i) && isPrimeNum(n - i)) ans = i;
        }

        printf("%d %d\n", ans, n - ans);
    }
}