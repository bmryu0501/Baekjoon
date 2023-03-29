#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct client {
    client(int age, string name) : age(age), name(name) {}
    int age;
    string name;
};

bool operator<(const client &lhs, const client &rhs) {  
    return lhs.age < rhs.age;
}  

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    /* 입력 */
    int N, tmp_age;
    string tmp_name;
    vector<client> arr;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> tmp_age >> tmp_name;
        arr.push_back(client(tmp_age, tmp_name));
    }

    /* 풀이 */
    stable_sort(arr.begin(), arr.end());

    /* 출력 */
    for(int i = 0; i < N; i++) {
        cout << arr[i].age << " " << arr[i].name << '\n';
    }
}