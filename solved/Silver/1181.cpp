#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    if(a.length() == b.length()) // 길이가 같으면 사전순
        return a < b;
    else return a.length() < b.length(); // 길이가 짧은 순서로
}

int main() {
    int N;
    string tmp;
    vector<string> arr;

    /* 입력 */
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    /* 풀이 */
    sort(arr.begin(), arr.end(), comp); // 정렬
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); // 중복 제거

    /* 출력 */
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\n";
    }
}