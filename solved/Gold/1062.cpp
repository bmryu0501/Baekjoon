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
int answer;

int max(int a, int b) {
    return a>b?a:b;
}

void init() {
    acint = 0;
    acint |= (1 << ('a' - 'a'));
    acint |= (1 << ('c' - 'a'));
    acint |= (1 << ('i' - 'a'));
    acint |= (1 << ('n' - 'a'));
    acint |= (1 << ('t' - 'a'));

    answer = 0;

    used_char = acint;
}

void dfs(int using_char, int num_using, int idx_next) {
    if(num_using == K) {
        int readable = 0;
        for(int i=0;i<N;i++) {
            if((bits[i] & using_char) == bits[i]) readable++;
        }

        answer = max(answer, readable);
        return;
    }

    for(int i=idx_next;i<MAX_K;i++) {
        if((used_char & (1<<i)) != 0) { // when if char is used, pick
            dfs(using_char | (1<<i), num_using+1, i+1);
        }
    }
}

void input(int N, int K) {
    init();

    for(int i=0;i<N;i++) {
        cin >> inputs[i];
        bits[i] |= acint;
        int len = strlen(inputs[i]) - 4;
        for(int j=4;j<len;j++) { // from after "anta" to before "tica"
            bits[i] |= (1 << (inputs[i][j] - 'a'));
            used_char |= (1 << (inputs[i][j] - 'a'));
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;
    input(N, K);

    if(K < 5) { // Cannot even read "anta" and "tica"
        cout << 0;
        return 0;
    }

    int num_used = 0;
    for(int i=0;i<MAX_K;i++) if((used_char & (1 << i)) != 0) num_used++;
    if(num_used <= K) {
        cout << N;
        return 0;
    }

    // void dfs(int using_char, int num_using, int idx_next)
    dfs(0, 0, 0);

    cout << answer;

    return 0;
}