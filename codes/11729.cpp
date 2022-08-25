#include <iostream>

using namespace std;

/* �Լ� */
// N�� from���� to�� �ű��, Ȱ���� �� �ִ� ��븦 by�� ����
void hanoi(int N, int from, int to, int by) {
	if(N == 1) {
		printf("%d %d\n", from, to, by);
		return;
	}

	hanoi(N - 1, from, by, to); // �ڽ� ���� ������ by�� �Űܳ��� ��
	printf("%d %d\n", from, to); // �� �� �ڽ��� �ű�
	hanoi(N - 1, by, to, from); // by�� �Ű�� ������ �ڽ� ���� �ű�
}

int main() {
	int N;

	scanf("%d", &N);
	// �ϳ��� ž �ű�� �ּ� Ƚ��
	// (2^N)-1
	printf("%d\n", (1 << N) - 1); 

	// N�� 1���� 3���� �ű�
	hanoi(N, 1, 3, 2);
}