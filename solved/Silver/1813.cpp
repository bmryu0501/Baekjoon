#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 51

int arr[MAX_N];
int N;

int solve() {
    for(int i=N;i>0;--i) {
        if(arr[i] == i) return i;
    }
    if(arr[0]) return -1;
    return 0;
}

int main() {
    cin >> N;
    for(int i=0;i<N;++i) {
        int t;
        cin >> t;
        arr[t]++;
    }

    cout << solve();

    return 0;
}