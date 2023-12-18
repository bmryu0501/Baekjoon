/*
퇴사
https://www.acmicpc.net/problem/14501
*/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 16
#define MAX_T 5
#define MAX_P 1000

int N;
int T[MAX_N];
int P[MAX_N];
int memo[MAX_N];

int max(int a, int b) {
    return a>b?a:b;
}

int dp(){
    for(int i=N-1;i>=0;--i) {
        int next = i + T[i];
        if(next > N) memo[i] = memo[i+1];
        else memo[i] = max(memo[i+1], memo[next] + P[i]);
    }

    return memo[0];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> T[i] >> P[i];
    }

    cout << dp();

    return 0;
}