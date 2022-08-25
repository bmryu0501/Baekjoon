#include <iostream>

using namespace std;

/* 함수 */
// (0, 0) ~ (N - 1, N - 1)을 좌표로 나타냈을 때 *을 찍는 조건
void star(int i, int j, int n) {
    // (i/n)과 (j/n)을 3으로 나눴을 때 나머지가 1일 때 빈칸
	if ((i/n) % 3 == 1 && (j/n) % 3 == 1) {
		printf(" ");
	} else if (n < 3) { // 끝까지 위의 경우가 아닐 경우
		printf("*");
	} else { // 재귀적으로 확인
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