#include <iostream>
#include <string>
using namespace std;

int main() {
    string buf;
    while(true) {
        getline(cin, buf);
        if(buf == "") break;
        cout << buf << '\n';
    }

    return 0;
}