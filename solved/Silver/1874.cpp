/*
 * Author: Byeongmin Ryoo
 * Blog: https://velog.io/@kkoala
 * Contact: bmformail@naver.com
 */

#include <iostream>
#include <vector>

using namespace std;

/* 조건 */
#define MAX_N 100000

/* 변수 */
int N, tmp;
int start = 1;
bool flag = true;
vector<int> stack;
vector<bool> result;

/* 함수 */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* 입력 */
    cin >> N;

    /* 풀이 */
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        if(start <= tmp) {
            for(int j = start; j <= tmp; j++) {
                stack.push_back(j);
                result.push_back(true);
                start = j+1;
            }
            stack.pop_back();
            result.push_back(false);
        } else {
            if(stack.back() == tmp) {
                stack.pop_back();
                result.push_back(false);
            } else {
                flag = false;
                break;
            }
        }
    }

    /* 출력 */
    if(flag) {
        for(int i = 0; i < N * 2; i++) {
            cout << (result[i] ? "+\n" : "-\n");
        }
    } else {
        cout << "NO\n";
    }
}