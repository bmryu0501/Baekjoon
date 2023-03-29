#include <iostream>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(b>0) {if(a>0) cout << 1; else cout << 2;}
    if(b<0) {if(a<0) cout << 3; else cout << 4;}
    cout << endl;
}