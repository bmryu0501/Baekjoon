#include <iostream>
#include <cstdint>

using namespace std;

typedef unsigned long long ull;

#define MAX_N 100005
#define MAX_Q 300005
#define MAX_x 1e6

ull N, Q, op, x, y;
ull arr[MAX_N];
ull sum;
int top=1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    for(int i=0;i<Q;++i) {
        cin >> op >> x >> y;
        switch(op) {
            case 1:
                arr[y] += x;
                if(y == N+1) break;
                sum += x;
                top = (arr[top] > arr[y]) ? top : y;
                break;
            case 2:
                cout << ((arr[N+1]+x > arr[top] && (arr[N+1]+x)*N > sum+y) ? "YES" : "NO") << "\n";
                break;
        }
    }

    return 0;
}