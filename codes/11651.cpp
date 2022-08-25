#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int N, x, y;
    pair<int, int> input[100000];

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d%d", &x, &y);
        input[i] = make_pair(x, y);
    }

    sort(input, input+N, comp);

    for(int i = 0; i < N; i++) {
        printf("%d %d\n", input[i].first, input[i].second);
    }
}