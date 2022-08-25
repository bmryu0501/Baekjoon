#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5e5;

int N, BIT[MAXN + 1];
long long ans = 0;
vector<pair<int, int>> vec;

long long sum(int i) {
    long long ret = 0;
    for(; i > 0; i &= i - 1)
        ret += BIT[i];
    return ret;
}

void add(int i, long long v) {
    for (; i <= N; i += i & -i)
        BIT[i] += v;
}


int main() {
    scanf("%d", &N);
    vec.resize(N + 1);
    for(int i = 1; i <= N; i++) {
        int k;
        scanf("%d", &k);
        vec[i] = {-k, -i};
    }

    sort(vec.begin() + 1, vec.end());

    for(int i = 1; i <= N; i++) {
        ans += sum(-vec[i].second);
        add(-vec[i].second, 1);
    }

    printf("%lld", ans);
}