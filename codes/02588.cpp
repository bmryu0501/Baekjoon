#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    for(int i = 0; i < 3; i++) {
        int cnt = 1;
        for(int k = 0; k < i; k++) {cnt *= 10;}
        cout << a * ((b/cnt)%10) << endl;
    }
    cout << a*b;
}