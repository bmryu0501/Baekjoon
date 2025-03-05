#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_LEN 50005

string list[] = {
    "h", "li", "na", "k", "rb", "cs", "fr", "be", "mg", "ca", "sr", "ba", "ra", "sc", "y", "ti", "zr", "hf", "rf", "la", "ac",
    "v", "nb", "ta", "db", "ce", "th", "cr", "mo", "w", "sg", "pr", "pa", "mn", "tc", "re", "bh", "nd", "u", "fe", "ru", "os",
    "hs", "pm", "np", "co", "rh", "ir", "mt", "sm", "pu", "ni", "pd", "pt", "ds", "eu", "am", "cu", "ag" ,"au", "rg", "gd", "cm",
    "zn", "cd", "hg", "cn", "tb", "bk", "b", "al", "ga", "in", "tl", "dy", "cf", "c", "si", "ge", "sn", "pb", "fl", "ho", "es",
    "n", "p", "as", "sb", "bi", "er", "fm", "o", "s", "se", "te", "po", "lv", "tm", "md", "f", "cl", "br", "i", "at", "yb", "no",
    "he", "ne", "ar", "kr", "xe", "rn","lu", "lr" };
const int num_list = 114;

string word;
bool visit[MAX_LEN];

bool check() {
    cin >> word;
    memset(visit, 0, sizeof(visit));

    int len = word.size();
    queue<int> q;
    q.push(0);
    visit[0] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(now == len) return true;

        string tmp1, tmp2;
        tmp1 = tmp2 = "";
        tmp1 += word[now];
        tmp2 += word[now] + word[now+1];

        for(int i=0;i<num_list;++i) {
            if(tmp1 == list[i] && visit[now+1] == false) {
                visit[now+1] = true;
                q.push(now+1);
            }
            if(tmp2 == list[i] && visit[now+2] == false) {
                visit[now+2] = true;
                q.push(now+2);
            }
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        if(check()) cout << "YES\n";
        else cout << "NO\n";
    }
}