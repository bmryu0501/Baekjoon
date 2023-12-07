/***************************************************
 * 16637 괄호 추가하기
 * 브루트포스알고리즘
****************************************************/

#include <iostream>
#include <string>

using namespace std;

#define MAX_N 19

int N;
string expression;
int ans;

int max(int a, int b) {
    return a>b?a:b;
}

int calc(int a, int b, char c) {
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
}

void solv(int idx, int cur) {
    if(idx > N-1) {
        ans = max(ans , cur);
        return;
    }

    char op = idx == 0 ? '+' : expression[idx-1];

    // Calc now
    solv(idx+2, calc(cur, expression[idx]-'0', op));

    // calc later
    if(idx+2 < N) {
        int next = calc(expression[idx]-'0', expression[idx+2]-'0', expression[idx+1]);
        solv(idx+4, calc(cur, next, op));
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> expression;

    ans = -21e8;
    solv(0, 0);

    cout << ans;
}