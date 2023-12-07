#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 50 // number of words
#define MAX_K 26 // number of alphabets
#define MAX_LEN 16 // (15 characters) + (1 null character)

int N, K;
char inputs[MAX_N][MAX_LEN]; // input strings
int bits[MAX_N]; // used bits for each inputs
int used_char; // used characters in bits
int acint; // bits for "anta tica"
int min_unreadable; // answer = N - min_impossible

int min(int a, int b) {
    return a<b?a:b;
}

void init() {
    acint = 0;
    acint | 1 << 'a' - 'a';
    acint | 1 << 'c' - 'a';
    acint | 1 << 'i' - 'a';
    acint | 1 << 'n' - 'a';
    acint | 1 << 't' - 'a';

    used_char = acint;

    min_unreadable = N;
}

void dfs(int using_char, int num_chars, int idx_next) {
    if(num_chars == K) { // base case
        int cnt = 0;
        for(int i=0;i<N;i++) {
            if(bits[i] & (bits[i] ^ using_char) > 0) cnt++; // check if unreadable
            if(cnt >= min_unreadable) break; // backtracking
        }
        min_unreadable = min(min_unreadable, cnt);
    }

    // recursive
    for(int i=idx_next; i<MAX_K; i++) {
        if(used_char & (1 << idx_next)) { // if char is used
            dfs(using_char | (1 << idx_next), num_chars + 1, i+1);
        }
    }
}

int check(int N, int K) {
    if(K < 5) return 0; //acint

    init();

    for(int i=0;i<N;i++) {
        cin >> inputs[i];
        bits[i] | acint;
        int len = strlen(inputs[i]) - 4;
        for(int j=4;j<len;j++) { // from after "anta" to before "tica"
            bits[i] | 1 << (inputs[i][j] - 'a');
            used_char | 1 << (inputs[i][j] - 'a');
        }
    }

    dfs(acint, 5, 0);

    return N - min_unreadable;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;

    cout << check(N, K);

    return 0;
}