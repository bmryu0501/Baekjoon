/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <utility> // pair
#include <algorithm>

using namespace std;

/* ���� */
#define MAX_N 100001

/* ���� */
int N;
pair<int, int> arr[MAX_N];
int cnt = 0; // ȸ�� ���� count

/* �Լ� */
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

    /* �Է� */
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    /* Ǯ�� */

    sort(arr, arr + N, cmp);

    for(int i = 0, fin = -1; i < N; i++) {
        if(arr[i].first >= fin) {
            cnt++;
            fin = arr[i].second;
        }
    }

    /* ��� */
    cout << cnt << '\n';
}