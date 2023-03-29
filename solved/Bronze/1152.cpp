#include <iostream>
#include <string.h>

# define MAX_STR_LEN 1000001

using namespace std;

int main() {
    char str[MAX_STR_LEN];
    int len, cnt = 1;
    cin.getline(str, MAX_STR_LEN);
    len = strlen(str);

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') cnt++;
    }

    if(str[0] == ' ') {
      for(int i = 0; str[i] == ' '; i++) cnt--;
    }
    if(str[len - 1] == ' ') {
      for(int i = len - 1; str[i] == ' '; i--) cnt--;
    }

    printf("%d\n", cnt);
}

