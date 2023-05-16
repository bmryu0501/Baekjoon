#include <iostream>
using namespace std;

#define INF 21e8
#define MAX_L 100000000
#define MAX_N 100

// 우 하 좌 상
int dy[4] = { 0, -1, 0, 1 }; // 홀수: 하상
int dx[4] = { 1, 0, -1, 0 }; // 짝수: 우좌

struct Line {
	int x, y;
	int len;
	int dir;
};

int L, N;
Line lines[MAX_N+1];
int x, y, len, dir, cur_time;
int ans = INF;

void check(int idx) {
	Line* now = &lines[idx];
	if (x < -L) ans = cur_time - (L - now->x) + 1;
	else if (x > L) ans = min(ans, cur_time + (L - now->x) + 1);
	else if (y < -L) ans = min(ans, cur_time - (L - now->y) + 1);
	else if (y > L) ans = min(ans, cur_time + (L - now->y) + 1);

	for (int i = 0; i < idx-1; i++) {
		Line* target = &lines[i];

		// 오른쪽
		if (now->dir == 0) {
			// 같은 방향
			if (target->dir == 0) {
				if (now->y != target->y) continue; // 같은 선상에 없다
				if (now->x > target->x) continue; // now가 이미 오른쪽에 있다
				if (target->x - now->x > now->len) continue; // 닿지 않는다
				ans = min(ans, cur_time + (target->x - now->x));
				// 교차, 하
			}
			else if (target->dir == 1) {
				if (target->y - target->len > now->y) continue; // 같은 선상에 없다
				if (now->y > target->y) continue; // 이미 아래쪽에 있다
				if (target->x - now->x > now->len) continue; // 닿지 않는다
				ans = min(ans, cur_time + (target->x - now->x));
				// 마주보는 방향
			}
			else if (target->dir == 2) {
				if (now->y != target->y) continue; // 같은 선상에 없다
				if (now->x > target->x) continue; //  target이 이미 왼쪽에 있다
				if (target->x - target->len - now->x > now->len) continue; // 닿지 않는다.
				ans = min(ans, cur_time + (target->x - target->len - now->x));
				// 교차, 상
			}
			else if (target->dir == 3) {
				if (target->y + target->len < now->y) continue; // 같은 선상에 없다
				if (now->y < target->y) continue; // 이미 위쪽에 있다
				if (target->x - now->x > now->len) continue; // 닿지 않는다
				ans = min(ans, cur_time + (target->x - now->x));
			}
			continue;
			// 아래쪽
		}
		else if (now->dir == 1) {
			// 교차, 우
			if (target->dir == 0) {
				if (target->x + target->len < now->x) continue; // 같은 선상에 없다
				if (now->x < target->x) continue;// 이미 오른쪽에 있다
				if (now->y - target->y > now->len) continue; // 닿지 않는다
				ans = min(ans, cur_time + (now->y - target->y));
				// 같은 방향
			}
			else if (target->dir == 1) {
				if (now->x != target->x) continue; // 같은 선상에 없다
				if (now->y < target->y) continue; // now가 이미 아래쪽에 있다
				if (now->y - target->y > now->len) continue; // 닿지 않는다
				ans = min(ans, cur_time + (now->y - target->y));
				// 교차, 좌
			}
			else if (target->dir == 2) {
				if (target->x - target->len > now->x) continue; // 같은 선상에 없다
				if (now->x > target->x) continue; // 이미 왼쪽에 있다.
				if (now->y - target->y > now->len) continue; // 닿지 않는다
				ans = min(ans, cur_time + (now->y - target->y));
				// 마주보는 방향
			}
			else if (target->dir == 3) {
				if (now->x != target->x) continue; // 같은 선상에 없다
				if (now->y < target->y) continue;// target이 이미 위쪽에 있다
				if (now->y - (target->y + target->len) > len) continue; // 닿지 않는다
				ans = min(ans, cur_time + (now->y - (target->y + target->len)));
			}
			// 왼쪽
		}
		else if (now->dir == 2) {
			// 마주보는 방향
			if (target->dir == 0) {
				if (now->y != target->y) continue;
				if (now->x < target->x) continue;
				if (now->x - (target->x + target->len) > len) continue;
				ans = min(ans, cur_time + (now->x - (target->x + target->len)));
				// 교차, 하
			}
			else if (target->dir == 1) {
				if (now->x > target->x) continue;
				if (now->y > target->y) continue;
				if (now->x - target->x > len) continue;
				ans = min(ans, cur_time + (now->x - target->x));
				// 같은 방향
			}
			else if (target->dir == 2) {
				if (now->x != target->x) continue;
				if (now->y < target->y) continue;
				if (now->x - target->x > len) continue;
				ans = min(ans, cur_time + (now->x - target->x));
				// 교차, 상
			}
			else if (target->dir == 3) {
				if (now->x < target->x) continue;
				if (now->y < target->y) continue;
				if (now->x - target->x > len) continue;
				ans = min(ans, cur_time + (now->x - target->x));
			}
			// 위쪽
		}
		else if (now->dir == 3) {
			// 교차, 우
			if (target->dir == 0) {
				if (now->y > target->y) continue;
				if (now->x < target->x) continue;
				if (target->y - now->y > len) continue;
				ans = min(ans, cur_time + (target->y - now->y));
				// 마주보는 방향
			}
			else if (target->dir == 1) {
				if (now->x != target->x) continue;
				if (now->y > target->y) continue;
				if (target->y - target->len - now->y > len) continue;
				ans = min(ans, cur_time + (target->y - target->len - now->y));
				// 교차, 좌
			}
			else if (target->dir == 2) {
				if (now->y > target->y) continue;
				if (now->x > target->x) continue;
				if (target->y - now->y > len) continue;
				ans = min(ans, cur_time + (target->y - now->y));
				// 같은 방향
			}
			else if (target->dir == 3) {
				if (now->x != target->x) continue;
				if (now->y > target->y) continue;
				if (target->y - now->y > len) continue;
				ans = min(ans, cur_time + (target->y - now->y));
			}
		}
	}
}

int main() {
	cin >> L >> N;

	char turn;
	for (int i = 0; i < N; i++) {
		cin >> len >> turn;
		lines[i].y = y;
		lines[i].x = x;
		lines[i].len = len;
		lines[i].dir = dir;

		y += dy[dir] * len;
		x += dx[dir] * len;
		if (turn == 'L') dir = (dir + 3) % 4;
		else dir = (dir + 1) % 4;

		Line* now = &lines[i];

		check(i);
		if (ans < 21e8) break;

		cur_time += len;
	}

    if(ans == 21e8) {
        lines[N].y = y;
        lines[N].x = x;
        lines[N].len = MAX_L * 2 + 1;
        lines[N].dir = dir;
        check(N);
    }

	cout << ans;

	return 0;
}
