/***************************************************
 * 문자열 폭발
 * https://www.acmicpc.net/problem/9935
****************************************************/

#include <iostream>

using namespace std;

/* condition */
#define MAX_LEN 1000000
#define MAX_BOMB_LEN 36

/* variables */
char input[MAX_LEN];
char output[MAX_LEN];
char bomb[MAX_BOMB_LEN];

/* functions */
int getLength(const char* str) {
    const char* p = str;
    while(*p != '\0') {*p++;}
    return p-str-1;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* input */
    cin >> input >> bomb;

    /* solving */
    int input_size = getLength(input);
    int bomb_size = getLength(bomb);

    const char* read = input;
    const char* write = output;
    while(input_size--) {
        
    }

    /* output */
}