#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string A, B, tmp; // 0 < A, B < 10^10000
    char C[10000]; // ������ �迭�� null
    bool carry = 0; // adder�� carry

    cin >> A >> B;

    // A�� ���ڸ� ���ڷ�
    if(A.length() < B.length()) {
        tmp = A;
        A = B;
        B = tmp;
    }

    // LD: Long Digit, �� ���� �ڸ���
    // SD: Short Digit, ª�� ���� �ڸ���
    int LD = A.length();
    int SD = B.length();

    // �������� string���� ������ֱ� ���� null�߰�
    C[LD] = '\0';

    for(int i = 1; i <= LD; i++) {
        if(i <= SD) { // ª�� ���� + �� ����
            C[LD - i] = ((A[LD - i] - '0') + (B[SD - i] - '0') + carry) % 10 + '0';
            if((A[LD - i] - '0') + (B[SD - i] - '0') + carry >= 10) carry = 1;
            else carry = 0;
        } else { // ���̻� ���� ª�� ���ڰ� ���� ��
            if((A[LD - i] - '0') + carry < 10) {
                C[LD - i] = A[LD - i] + carry;
                carry = 0;
            } else {
                C[LD - i] = ((A[LD - i] - '0') + carry) % 10 + '0';
                carry = 1;
            }
        }
    }

    if(carry == 1) printf("1"); // �ְ� �ڸ��� ������ 10�� �Ѿ�� ��
    printf("%s\n", C);
}