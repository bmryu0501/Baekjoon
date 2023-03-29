#include <iostream>

using namespace std;

int main() {
    static int N, count[10001] = {0, };
    scanf("%d", &N);

    // 입력 받고 count해줌
    for(int tmp, i = 0; i < N; i++) {
        scanf("%d", &tmp);
        count[tmp]++;
    }

    for(int i = 0; i < 10001; i++)
        for(int j = count[i]; j > 0; j--)
            printf("%d\n", i);
}