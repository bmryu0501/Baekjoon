#include <iostream>
#define MAX_N 100000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int answer = -21e8;
    int arr[MAX_N+1];
    arr[0] = 0;

    int i = 1;
    for(;i<K;i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for(;i<=N;i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
        if(answer < arr[i]-arr[i-K]) answer = arr[i]-arr[i-K];
    }

    cout << answer;

    return 0;
}