#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C, N, tmp, cnt, sum;
    vector<int> vec;
    
    scanf("%d", &C);

    for(int i = 0; i < C; i++) {
        vector<int>().swap(vec);
        cnt = 0;
        sum = 0;

        scanf("%d", &N);

        for(int j = 0; j < N; j++) {
            scanf("%d", &tmp);
            vec.push_back(tmp);
            sum = sum + vec[j];
        }

        for(int j = 0; j < N; j++) {
            if(vec[j] > sum / N) cnt++;
        }

        printf("%.3f%%\n", (float)cnt/(float)N*100);
    }
}