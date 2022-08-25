#include <iostream>

using namespace std;

int main() {
    char str[1000001];
    scanf("%s", str);
    int max = 0;

    int alphabet['Z' - 'A' + 1] = {0, };
    
    for(int i = 0; str[i] != NULL; i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            alphabet[str[i] - 'a']++;
        else
            alphabet[str[i] - 'A']++;
    }

    bool dup_flag = false;

    for(int i = 1; i < 'Z' - 'A' + 1; i++) {
        if(alphabet[i] > alphabet[max]) {
            max = i;
            dup_flag = false;
        } else if(alphabet[i] == alphabet[max]) {
            dup_flag = true;
        }
    }
    if(dup_flag == true) printf("?\n");
    else printf("%c\n", 'A' + max);
}