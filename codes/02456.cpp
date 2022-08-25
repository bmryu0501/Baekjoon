#include <iostream>

using namespace std;

const int MAX = 1e3;
int N, arr[4][4], sum[4], ans = 1;

int main() {
    scanf("%d", &N);
    for(int i = 1; i < N+1; i++) {
        for(int j = 1; j < 4; j++) {
            int tmp;
            scanf("%d", &tmp);
            arr[j][tmp]++;
            sum[j] += tmp;
        }
    }
    
    if(sum[1] != sum[2] && sum[2] != sum[3] && sum[1] != sum[3]) {
        int tmp = 2;
        if(sum[2] < sum[3]) tmp = 3;
        if(sum[1] < sum[tmp]) ans = tmp;
        printf("%d %d", ans, sum[ans]);
        return 0;
    }

    for(int i = 1; i < 4; i++) sum[i] = arr[i][1] + (arr[i][2] * (N + 1)) + (arr[i][3] * (N + 1) * (N + 1));
    int tmp = 2;
    if(sum[2] < sum[3]) tmp = 3;
    if(sum[1] < sum[tmp]) ans = tmp;


    if((ans != 3 && sum[1] == sum[2] ) || (ans != 1 && sum[2] == sum[3]) || (ans != 2 && sum[1] == sum[3])) {
        printf("%d %d", 0, arr[ans][1] + arr[ans][2] * 2 + arr[ans][3] * 3);
        return 0;
    }

    printf("%d %d", ans, arr[ans][1] + arr[ans][2] * 2 + arr[ans][3] * 3);

    return 0;
}