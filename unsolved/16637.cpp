/***************************************************
 * 16637 괄호 추가하기
 * 브루트포스알고리즘
****************************************************/

#include <iostream>
#include <string>

using namespace std;

/* condition */
#define MAX_N 19

/* variables */
int N;
string expression;
int num[MAX_N];

/* functions */
int max(int a, int b) {
    return a>b?a:b;
}

int operation(int a, int b, char c) {
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
}

/**/
int solv(int head, int tail) {
    cout << "(" << head << ", " << tail << ")\n\n";

    if(head == tail) return num[head];
    if(head == tail-2) return operation(num[head], num[head+2], expression[head+1]);

    return max(operation(solv(head, head), solv(head+2, tail), expression[head+1]),
               operation(solv(head, head+2), solv(head+4, tail), expression[head+3]));
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> N;
    cin >> expression;
    for(int i=0;i<N;i+=2) {
        num[i] = expression[i]-'0';
    }

    /* solving */
    int result = solv(0, N-1);

    /* output */
    cout << result;
}