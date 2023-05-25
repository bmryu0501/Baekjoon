#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAX_N 50
#define MAX_LEN 50

struct compare {
    char minsik[21] = "abkdeghilmncoprstuwy";

    bool operator()(string A, string B) {
        int lenA = A.length();
        int lenB = B.length();
        
    }
};

priority_queue<string, vector<string>, compare> q;

int main() {
    int N;
    cin >> N;

    return 0;
}