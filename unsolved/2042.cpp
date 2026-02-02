#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 1000005
#define MAX_M 10001
#define MAX_K 10001

int N, M, K;
long long* tree;
long long arr[MAX_N];
int level;

long long getSum(int now, int start, int end, int from, int to) {
    if(start == end) return tree[now];

    int mid = (start + end) / 2;
    return getSum(now*2, start, mid, from, to) + getSum(now*2+1, mid+1, end, from, to);
}

void update(int node, int target, int start, int end, long long diff) {
    if(node < start || end < node) return;

    tree[node] += diff;
    if(start == target) return;

    int mid = (start + end) / 2;
    update(node*2, target, start, mid, diff);
    update(node*2+1, target, mid+1, end, diff);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M >> K;
    level = ceil(log2(N));
    tree = new long long[1 << (level+1) + 5];

    for(int i=1;i<=N;i++) {
        cin >> arr[i];
        update(i, i, i, i, arr[i]);
    }

    int a, b, c;
    for(int i=0;i<M+K;i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            // update(node, target, start, end, diff)
            update(1, b, 1, N, c - arr[b]);
        } else if (a == 2) {
            // getSum(now, start, end, from, to)
            getSum(1, b, c, b, c);
        }
    }

    return 0;
}