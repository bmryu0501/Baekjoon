#include <iostream>

using namespace std;

/* 조건 */
#define MAX 8

/* 변수 */
int N, M, output[MAX];

/* 함수 */
void tracker(int count) { // DFS하는 함수, count번째 과정임을 의미
    if(count == M) { // M만큼 output에 들어가면 출력 후 return
        for(int i = 0; i < M; i++) {
            cout << output[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        output[count] = i + 1;
        tracker(count + 1);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* 입력 */
    cin >> N >> M;

    /* 풀이 */
    tracker(0);

    /* 출력 */

}