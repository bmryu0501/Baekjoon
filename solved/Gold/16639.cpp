/*
16639 괄호 추가하기 3
https://www.acmicpc.net/problem/16639
*/


#include <iostream>
#include <string>

#define MAX_N 19

using namespace std;

int N;
char expr[MAX_N+1];

int DP_max[MAX_N][MAX_N];
int DP_min[MAX_N][MAX_N];
bool DP_updated[MAX_N][MAX_N];

int calc(int a, int b, char op) {
    switch(op) {
        case '+': return a+b;
        case '*': return a*b;
        case '-': return a-b;
    }

    return -1;
}

void dp(int start, int end) {
    if(start == end) {
        DP_max[start][end] = expr[start] - '0';
        DP_min[start][end] = expr[start] - '0';

        DP_updated[start][end] = true;

        return;
    }

    int MAX = -2147483648;
    int MIN = 2147483647;

    for(int i=start+1;i<end;i+=2) {
        if(!DP_updated[start][i-1]) dp(start, i-1);
        if(!DP_updated[i+1][end]) dp(i+1, end);

        MAX = max(MAX, calc(DP_max[start][i-1], DP_max[i+1][end], expr[i]));
        MAX = max(MAX, calc(DP_max[start][i-1], DP_min[i+1][end], expr[i]));
        MAX = max(MAX, calc(DP_min[start][i-1], DP_max[i+1][end], expr[i]));
        MAX = max(MAX, calc(DP_min[start][i-1], DP_min[i+1][end], expr[i]));

        MIN = min(MIN, calc(DP_max[start][i-1], DP_max[i+1][end], expr[i]));
        MIN = min(MIN, calc(DP_max[start][i-1], DP_min[i+1][end], expr[i]));
        MIN = min(MIN, calc(DP_min[start][i-1], DP_max[i+1][end], expr[i]));
        MIN = min(MIN, calc(DP_min[start][i-1], DP_min[i+1][end], expr[i]));
    }

    DP_max[start][end] = MAX;
    DP_min[start][end] = MIN;
    DP_updated[start][end] = true;
}

int main() {

    cin >> N;
    cin >> expr;

    dp(0, N-1);
    cout << DP_max[0][N-1];

    return 0;
}