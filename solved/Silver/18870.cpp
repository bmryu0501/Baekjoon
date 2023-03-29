// 블로그 https://velog.io/@kkoala

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /* 빠른 cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* 입력 */
    int N;
    cin >> N;
    vector<int> input, position;

    /* 풀이 */
    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        input.push_back(tmp);
        position.push_back(tmp);
    }

    sort(position.begin(), position.end());
    position.erase(unique(position.begin(), position.end()), position.end());

    /* 출력 */
    for(int i = 0; i < N; i++) {
        cout << lower_bound(position.begin(), position.end(), input[i]) - position.begin() << ' ';
    }
}
