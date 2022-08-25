#include <iostream>

using namespace std;

int main() {
    int x, y, w, h;

    scanf("%d%d%d%d", &x, &y, &w, &h);

    printf("%d\n", (x < w - x)? \
                    (x < y)? \
                        (x < h - y)? \
                            x : h - y : \
                        (y < h - y)? \
                            y : h - y : \
                    (w - x < y)? \
                        (w - x < h - y)? \
                            w - x : h - y : \
                        (y < h - y)? \
                            y : h - y);
}