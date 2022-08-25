#include <iostream>

using namespace std;

/* 함수 */
// N을 from에서 to로 옮기며, 활용할 수 있는 장대를 by로 참조
void hanoi(int N, int from, int to, int by) {
	if(N == 1) {
		printf("%d %d\n", from, to, by);
		return;
	}

	hanoi(N - 1, from, by, to); // 자신 위의 원판을 by로 옮겨놔야 됨
	printf("%d %d\n", from, to); // 그 후 자신을 옮김
	hanoi(N - 1, by, to, from); // by로 옮겼던 원판을 자신 위로 옮김
}

int main() {
	int N;

	scanf("%d", &N);
	// 하노이 탑 옮기는 최소 횟수
	// (2^N)-1
	printf("%d\n", (1 << N) - 1); 

	// N을 1에서 3으로 옮김
	hanoi(N, 1, 3, 2);
}