#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2e6;
int N, C, arr[MAXN];

bool f(int x) {
    int tmp = 0;
    int cnt = C - 1;
    for(int i = 0; i < N; i++) {
        if((arr[i] - arr[tmp]) >= x) {
            cnt--;
            tmp = i;
        }
    }
    return cnt > 0;
}

int main() {
    scanf("%d%d", &N, &C);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);
    int lo = 0, hi = 1e9;
    while(lo + 1 != hi) {
        int mid = (lo + hi) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }

    printf("%d\n", lo);
}