#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string A, B, tmp; // 0 < A, B < 10^10000
    char C[10000]; // 마지막 배열은 null
    bool carry = 0; // adder의 carry

    cin >> A >> B;

    // A를 긴자리 숫자로
    if(A.length() < B.length()) {
        tmp = A;
        A = B;
        B = tmp;
    }

    // LD: Long Digit, 긴 숫자 자리수
    // SD: Short Digit, 짧은 숫자 자리수
    int LD = A.length();
    int SD = B.length();

    // 마지막에 string으로 출력해주기 위해 null추가
    C[LD] = '\0';

    for(int i = 1; i <= LD; i++) {
        if(i <= SD) { // 짧은 숫자 + 긴 숫자
            C[LD - i] = ((A[LD - i] - '0') + (B[SD - i] - '0') + carry) % 10 + '0';
            if((A[LD - i] - '0') + (B[SD - i] - '0') + carry >= 10) carry = 1;
            else carry = 0;
        } else { // 더이상 더할 짧은 숫자가 없을 때
            if((A[LD - i] - '0') + carry < 10) {
                C[LD - i] = A[LD - i] + carry;
                carry = 0;
            } else {
                C[LD - i] = ((A[LD - i] - '0') + carry) % 10 + '0';
                carry = 1;
            }
        }
    }

    if(carry == 1) printf("1"); // 최고 자리수 덧셈이 10을 넘어갔을 때
    printf("%s\n", C);
}