#include <iostream>

using namespace std;

const int MAXN = 1e6;

int N, M, K;
long long BIT[MAXN + 2];

long long sum(int i) {
    long long ret = 0;
    for(; i > 0; i &= i - 1)
        ret += BIT[i];
    return ret;
}

void add(int i, long long v) {
    for (; i < N + 1; i += i & -i)
        BIT[i] += v;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i < N + 1; i++) {
        int k;
        scanf("%d", &k);
        add(i, k);
    }

    for(int i = 0; i < M + K; i++) {
        int a;
        long long b, c;
        scanf("%d %lld %lld", &a, &b, &c);
        if(a == 1) add(b, c - (sum(b) - sum(b - 1)));
        else printf("%lld\n", sum(c) - sum(b - 1));
    }
}