#include <iostream>

using namespace std;

int main() {
    int N, cnt = 0;

    scanf("%d", &N);

    
    while(N % 5 > 0) { //5�� ����� �ƴϸ� �ݺ�
        N -= 3; // 3��ŭ ���� count
        cnt++;
        if(N == 0) { // 3�� ���� ������ ������ ��� �� ��� �� ����
            printf("%d\n", cnt);
            return 0;
        }
        else if(N < 3) { // 3�� ���µ� 3���� �۾� 3 �Ǵ� 5�� ���� �� ���� ���
            printf("-1\n"); // -1 ��� �� ����
            return 0;
        }
    }

    printf("%d\n", cnt + N/5); // 3�� �� �� 5�� ����� �� N�� 5�� ���� ���� ���
    return 0;
}