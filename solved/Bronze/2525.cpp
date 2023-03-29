#include <iostream>

using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    int C;
    cin >> C;

    h += C/60;
    m += C%60;
    h += m/60;
    h %= 24;
    m %= 60;

    cout << h << ' ' << m;

    return 0;
}