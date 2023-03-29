#include <iostream>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(b>=45) cout << a << " " << b-45 << endl;
    else if(a == 0) cout << 23 << " " << b+15 << endl;
    else cout << a-1 << " " << b+15 << endl;
}