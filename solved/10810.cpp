#include <iostream>

using namespace std;

#define MAX_N 101
#define MAX_M 101

int N, M;
int balls[MAX_N];

int main() {
    cin >> N >> M;
    while(M--) {
        int I, J, K;
        cin >> I >> J >> K;
        for(int i=I;i<=J;i++) balls[i] = K;
    }

    for(int i=1;i<=N;i++) cout << balls[i] << " ";

    return 0;
}