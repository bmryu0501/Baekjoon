#include <iostream>

using namespace std;

/* �Լ� */
// (0, 0) ~ (N - 1, N - 1)�� ��ǥ�� ��Ÿ���� �� *�� ��� ����
void star(int i, int j, int n) {
    // (i/n)�� (j/n)�� 3���� ������ �� �������� 1�� �� ��ĭ
	if ((i/n) % 3 == 1 && (j/n) % 3 == 1) {
		printf(" ");
	} else if (n < 3) { // ������ ���� ��찡 �ƴ� ���
		printf("*");
	} else { // ��������� Ȯ��
		star(i, j, n / 3);
	}
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(i, j, N);
		}
		printf("\n");
	}
}