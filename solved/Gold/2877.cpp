#include <iostream>
#include <bitset>

using namespace std;

/* condition */
#define MAX_K 10e9

/* variables */
int K;

/* functions */

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> K;

    /* solving */
    K++;
    string binary = bitset<32>(K).to_string();

    int idx = 0;
    while(binary[idx] == '0') idx++;
    for(int i = idx+1; i < 32; i++) {
        if(binary[i] == '0') binary[i] = '4';
        else binary[i] = '7';
    }

    /* output */
    cout << binary.substr(idx+1);
}