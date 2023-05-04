#include <iostream>
using namespace std;

#define MAX_N 100
#define MAX_M 100

int arr[MAX_N+1];

int main() {
    int N, M;
    cin >> N >> M;

    for(int i=1;i<=N;i++) arr[i] = i;

    while(M--) {
        int i, j;
        cin >> i >> j;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    for(int i=1;i<=N;i++) cout << arr[i] << " ";

    return 0;
}