#include <iostream>

using namespace std;

int main() {
    int N, count[8001] = {0, }, sum = 0;

    scanf("%d", &N);

    for(int tmp, i = 0; i < N; i++) {
        scanf("%d", &tmp);
        sum += tmp;
        count[tmp + 4000]++;
    }

    // »ê¼úÆò±Õ
    printf("%.0lf\n", (double)sum/N);

    // Áß¾Ó°ª
    for(int acc = 0, i = 0; i < 8001; i++) {
        acc += count[i];
        if(acc > N/2) {
            printf("%d\n", i - 4000);
            break;
        }
    }

    // ÃÖºó°ª
    int mode, max = 8000;
    for(int i = 8001; i-- > 0;) {
        if(count[max] < count[i]) {
            mode = i;
            max = i;
        } else if(count[max] == count[i]) {
            mode = max;
            max = i;
        }
    }
    printf("%d\n", mode - 4000);

    // ¹üÀ§
    for(int i = 8001; i-- > 0;) {
        if(count[i] > 0) {
            max = i;
            break;
        }
    }

    for(int i = 0; i < 8001; i++) {
        if(count[i] > 0) {
            printf("%d\n", max - i);
            break;
        }
    }
}