#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec;
    int N, a;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a);
        vec.push_back(a);
    }
    printf("%d %d\n", *min_element(vec.begin(), vec.end()), *max_element(vec.begin(), vec.end()));
}