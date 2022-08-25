#include <iostream>

int main() {
    int a, b, cnt;

    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", a+b);
    }
}