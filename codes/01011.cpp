#include <iostream>

using namespace std;

int main() {
    int T, x, y, dist, cnt;

    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d%d", &x, &y);
        dist = y - x;
        cnt = 0;
        for(int j = 1;; j++) {
            dist -= j;
            cnt++;
            if(dist < j) break;
            dist -= j;
            cnt++;
            if(dist < j) break;
        }
        if(dist > 0) cnt++;
        printf("%d\n", cnt);
    }
}