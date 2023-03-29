#include <iostream>

using namespace std;

bool isGroup(char str[101]) {
    bool alphabet['z' - 'a' + 1] = {0, };
    for(int i = 0; str[i] != '\0'; i++) {
        if(alphabet[str[i] - 'a'] == true && str[i-1] != str[i]) return false;
        alphabet[str[i] - 'a'] = true;
    }
    return true;
}

int main() {
    char str[101];
    int N, cnt = 0;

    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%s", str);
        if(isGroup(str)) cnt++;
    }

    printf("%d\n", cnt);
}