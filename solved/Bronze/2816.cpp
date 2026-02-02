#include <iostream>
#include <string>

using namespace std;

string arr[103];
int kbs1, kbs2;

int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> arr[i];
        if(arr[i] == "KBS1") kbs1 = i;
        if(arr[i] == "KBS2") kbs2 = i;
    }

    if(kbs1 < kbs2) {
        for(int i=0;i<kbs1;++i) cout << 1;
        for(int i=0;i<kbs1;++i) cout << 4;
        for(int i=0;i<kbs2;++i) cout << 1;
        for(int i=1;i<kbs2;++i) cout << 4;
    } else {
        for(int i=0;i<kbs2;++i) cout << 1;
        for(int i=0;i<kbs2;++i) cout << 4;
        for(int i=0;i<kbs1;++i) cout << 1;
        for(int i=0;i<kbs1;++i) cout << 4;
    }

    return 0;
}