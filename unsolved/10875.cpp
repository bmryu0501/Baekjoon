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

int ccw(Line line, int x, int y) {
	int op = line.x1*line.y2 + line.x2*y + x*line.y1;
	op -= line.y1*line.x2 + line.y2*x + y*line.x1;
	if(op > 0) return 1;
	if(op < 0) return -1;
	return 0;
}

bool check(int idx) {
	for(int i=0;i<idx-1;i++) {
		int abc = ccw(lines[idx], lines[i].x1, lines[i].y1);
		int abd = ccw(lines[idx], lines[i].x2, lines[i].y2);
		int cda = ccw(lines[i], lines[idx].x1, lines[idx].y1);
		int cdb = ccw(lines[i], lines[idx].x2, lines[idx].y2);

		if(abc * abd > 0 || cda * cdb > 0) return false;
	}

	return true;
}

int main() {
	cin >> L >> N;
	char t;
	for(int i=0;i<N;i++) {
		cin >> len >> t;

		lines[i].x1 = x;
		lines[i].y1 = y;
		x = x + len * dx[dir];
		y = y + len * dy[dir];
		lines[i].x2 = x;
		lines[i].y2 = y;

		if(t=='L') dir = (dir+3)%4;
		else dir = (dir+1)%4;

		if(check(i)) break;

		cur_time += len;
	}

	return 0;
}
