#include <iostream>

using namespace std;

int main() {
    int a, ans;
    ans = 0;
    cin >> a;
    for(int i = 1; i <= a; i++) {
        ans += i;
    }
    cout << ans << endl;
}