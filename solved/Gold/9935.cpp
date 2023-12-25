/***************************************************
 * 문자열 폭발
 * https://www.acmicpc.net/problem/9935
****************************************************/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_LEN 1000000
#define MAX_BOMB_LEN 36

char input[MAX_LEN+1];
char bomb[MAX_BOMB_LEN+1];
deque<char> dq;
deque<char> tmp;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* input */
    cin >> input >> bomb;

    /* solving */
    int len_input = strlen(input);
    int len_bomb = strlen(bomb);
    char last = bomb[len_bomb - 1];

    for(int i=0;i<len_input;++i) {
        dq.push_back(input[i]);
        if(input[i] == last) {
            for(int j=0;j<len_bomb;++j) {
                if(!dq.empty() && dq.back() == bomb[len_bomb - j - 1]) {
                    tmp.push_back(dq.back());
                    dq.pop_back();
                } else {
                    while(!tmp.empty()) {
                        dq.push_back(tmp.back());
                        tmp.pop_back();
                    }
                    break;
                }
            }
            while(!tmp.empty()) tmp.pop_back();
        }
    }

    /* output */
    if(dq.empty()) cout << "FRULA";
    else while(!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
}