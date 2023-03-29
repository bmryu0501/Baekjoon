#include <iostream>

#define _USE_MATH_DEFINES // for M_PI
#include <math.h>

using namespace std;

int main() {
    int R;

    scanf("%d", &R);

    printf("%.6f\n", R * R * M_PI);
    printf("%.6f\n", R * R * 2.0);
}