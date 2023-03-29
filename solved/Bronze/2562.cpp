#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    int a, max_idx;
    max_idx = 0;

    for(int i = 0; i < 9; i++) {
        scanf("%d", &a);
        vec.push_back(a);
    }

    for(int i = 0; i < 9; i++) {
        if(vec[max_idx] < vec[i]) max_idx = i;
    }

    printf("%d\n%d\n", vec[max_idx], max_idx+1);
}