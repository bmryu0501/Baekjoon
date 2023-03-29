#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
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