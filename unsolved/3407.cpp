#include <iostream>
#include <queue>

using namespace std;

#define MAX_LEN 50005
char* List[] = { "h", "li", "na", "k", "rb", "cs", "fr", "be", "mg", "ca", "sr", "ba", "ra", "sc", "y", "ti", "zr", "hf", "rf", "la", "ac",                  "v", "nb", "ta", "db", "ce", "th", "cr", "mo", "w", "sg", "pr", "pa", "mn", "tc", "re", "bh", "nd", "u", "fe", "ru", "os",                  "hs", "pm", "np", "co", "rh", "ir", "mt", "sm", "pu", "ni", "pd", "pt", "ds", "eu", "am", "cu", "ag" ,"au", "rg", "gd", "cm",                  "zn", "cd", "hg", "cn", "tb", "bk", "b", "al", "ga", "in", "tl", "dy", "cf", "c", "si", "ge", "sn", "pb", "fl", "ho", "es",                  "n", "p", "as", "sb", "bi", "er", "fm", "o", "s", "se", "te", "po", "lv", "tm", "md", "f", "cl", "br", "i", "at", "yb", "no",                  "he", "ne", "ar", "kr", "xe", "rn","lu", "lr" };

queue<int> q;

bool check(char* str) {
    q.push(0);
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
    }
}

int main() {
    int T;
    cin >> T;

    char word[MAX_LEN];

    while(--T) {
        if(check()) cout << "YES\n";
        else cout << "NO\n";
    }
}