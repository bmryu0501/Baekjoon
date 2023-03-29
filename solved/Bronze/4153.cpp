#include <iostream>

using namespace std;

int main() {
    int a = 1, b, c, tmp;

    while(1) {
        scanf("%d%d%d", &a, &b, &c);
        if(a == 0) break;

        if (a > c) {
            tmp = a;
            a = c;
            c = tmp;
        }

        if(b > c) {
            tmp = b;
            b = c;
            c = tmp;
        }

        printf("%s\n", a*a + b*b == c*c? "right" : "wrong");
    }
}