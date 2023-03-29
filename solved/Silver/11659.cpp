#include <iostream>
#define MAX_N 100000
#define MAX_M 100000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int arr[MAX_N+1];
    arr[0] = 0;
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int i, j;
    while(M--) {
        cin >> i >> j;
        cout << arr[j]-arr[i-1] << '\n';
    }

    return 0;
}