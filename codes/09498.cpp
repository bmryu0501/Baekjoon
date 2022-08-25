#include <iostream>

using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    if(a < 60) cout << "F" << endl;
    else if(a < 70) cout << "D" << endl;
    else if(a < 80) cout << "C" << endl;
    else if(a < 90) cout << "B" << endl;
    else cout << "A" << endl;
}