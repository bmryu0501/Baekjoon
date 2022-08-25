#include <iostream>

using namespace std;

int main() {
    int alphabet['z'-'a'+1];
    for(int i = 0; i < 'z'-'a'+1; i++)
        alphabet[i] = -1;
    char str[101];

    scanf("%s", &str);

    for(int i = 0; str[i] != NULL; i++) {
        if (alphabet[str[i] - 'a'] < 0) alphabet[str[i] - 'a'] = i;
    }

    for(int i = 0; i < 'z'-'a'+1; i++) {
        printf("%d ", alphabet[i]);
    }
}