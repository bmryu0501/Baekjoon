#include <iostream>
using namespace std;

#define MAX_N 50
#define MAX_M 50

int N, M;
int parent[MAX_N + 1];
int party[MAX_M][MAX_N + 1];

int Find(int a) {
	if (parent[a] == a) return a;
	else return Find(parent[a]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return;

    if(pa < pb) parent[pb] = pa;
    else parent[pa] = parent[pb];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i <= N; i++) parent[i] = i;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		parent[t] = 0;
	}

	for (int i = 0; i < M; i++) {
		cin >> party[i][0];
		cin >> party[i][1];
		for (int j = 2; j <= party[i][0]; j++) {
			cin >> party[i][j];
			Union(party[i][1], party[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool check = true;
		n = party[i][0];
		for (int j = 1; j <= n; j++) {
			if (Find(party[i][j]) == 0) check = false;
		}
		if (check) cnt++;
	}

	cout << cnt;

	return 0;
}