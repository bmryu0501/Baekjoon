#include <iostream>
#include <string>

using namespace std;

#define MAX_N 10004

int N;
string dp[MAX_N];

string sum(int a, int b) {
    string sa = dp[a];
    string sb = dp[b];
}

void fibo(int n) {
    if(dp[n].empty()) {
        fibo(n-1);
        fibo(n-2);
    }
    dp[n] = sum(n-1, n-2);
}

int main() {
    cin >> N;
    dp[0] = "0";
    dp[1] = "1";

    fibo(N);

    return 0;
}