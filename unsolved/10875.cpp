/*
10875번 뱀
https://www.acmicpc.net/problem/10875
*/

#include <iostream>
using namespace std;

#define INF 21e8
#define MAX_L 100000000
#define MAX_N 100

// 우 하 좌 상
int dy[4] = { 0, -1, 0, 1 }; // 홀수: 하상
int dx[4] = { 1, 0, -1, 0 }; // 짝수: 우좌

struct Line {
	int x1, y1;
	int x2, y2;
};

int L, N;
Line lines[MAX_N+1];
int x, y, len, dir, cur_time;
int ans = INF;

int ccw(Line l1, int x, int y) {
	int op = l1.x1*y + x*l1.y2 + l1.x2*l1.x1;
}

int main() {
	cin >> L >> N;

	return 0;
}
