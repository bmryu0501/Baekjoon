#include <iostream>

#include <math.h>

using namespace std;    

int main() {
    int T, x1, y1, r1, x2, y2, r2;
    float dist;

    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

        dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        if(dist == 0) { // 동심원
            if(r1 == r2) printf("-1\n"); // 같은 원
            else printf("0\n"); // 동심원이지만 지름이 다름
        } else if(dist > r1 + r2)
            printf("0\n"); // 외부에 있음
        else if(dist == r1 + r2 || dist + r1 == r2 || dist + r2 == r1)
            printf("1\n"); // 외접, 내접
        else if(dist + r1 < r2 || dist + r2 < r1)
            printf("0\n"); // 내부에 있음
        else printf("2\n");
    }
}