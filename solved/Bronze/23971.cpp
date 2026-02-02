/*
23971번 ZOAC 4
수학
사칙연산
*/

#include <iostream>
#include <cmath>
using namespace std;

double W, H, N, M;

int main() {
    cin >> W >> H >> N >> M;

    cout << (long long)ceil(W/(N+1)) * (long long)ceil(H/(M+1));

    return 0;
}