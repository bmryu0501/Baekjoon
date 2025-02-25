#include <iostream>

using namespace std;

int main() {
    int A, B, K, X;

    cin >> A >> B >> K >> X;

    int answer = 0;
    for(int i=A;i<=B;++i) if(i>=K-X && i<=K+X) answer++;

    if(answer == 0) cout << "IMPOSSIBLE";
    else cout << answer;

    return 0;
}