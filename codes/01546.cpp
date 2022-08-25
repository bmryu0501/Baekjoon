#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    float tmp, sum;
    sum = 0;
    vector<float> vec;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%f", &tmp);
        vec.push_back(tmp);
        sum += tmp;
    }

    printf("%f\n", sum / N / *max_element(vec.begin(), vec.end()) * 100);
}