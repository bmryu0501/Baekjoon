/*
10817 세 수
https://www.acmicpc.net/problem/10817
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A[3];
    for(int i=0;i<3;i++) cin >> A[i];
    sort(A, A+3);
    cout << A[1];

    return 0;
}