/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <utility> // pair
#include <algorithm>

using namespace std;

/* 조건 */
#define MAX_N 100001

/* 변수 */
int N;
pair<int, int> arr[MAX_N];
int cnt = 0; // 회의 개수 count

/* 함수 */
bool cmp(const pair<int, int> a, const pair<int, int> b) {
    if(a.second < b.second) return true;
    else if(a.second == b.second) return a.first < b.first;
    return false;
}

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    /* 풀이 */

    sort(arr, arr + N, cmp);

    for(int i = 0, fin = -1; i < N; i++) {
        if(arr[i].first >= fin) {
            cnt++;
            fin = arr[i].second;
        }
    }

    /* 출력 */
    cout << cnt << '\n';
}