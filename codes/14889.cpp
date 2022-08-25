/************************************
 * Author: Byeongmin Ryoo           *
 * Blog: https://velog.io/@kkoala   *
 * Contact: bmformail@naver.com     *
 ************************************/

#include <iostream>
#include <vector>

using namespace std;

/* 조건 */
#define MAXINT 2147483647
#define MAX 20

/* 변수 */
int N;
int arr[MAX][MAX];
int ability_diff = MAXINT; // 팀 능력치 차이
int ability_start, ability_link;
vector<int> start, link;

/* 함수 */
// 절댓값 반환
int abs(int a) {
    return (a < 0) ? (a * -1) : a;
}

void makeTeam(int idx) {
    // 재귀 종료
    if(idx == N) {
        if(start.size() == N/2 && link.size() == N/2) { // 두 팀의 수가 같을 때            
            // ability 계산
            ability_start = 0;
            ability_link = 0;
            for(auto i : start)
                for(auto j : start)
                    ability_start += arr[i][j];
            for(auto i : link)
                for(auto j : link)
                    ability_link += arr[i][j];

            // update ability_diff
            if(ability_diff > abs(ability_start - ability_link))
                ability_diff = abs(ability_start - ability_link);
        }
        return;
    }

    // 재귀
    // start 팀으로 한 번
    start.push_back(idx);
    makeTeam(idx+1);
    start.pop_back();

    // link 팀으로 한 번
    link.push_back(idx);
    makeTeam(idx+1);
    link.pop_back();

    return;
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
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    /* 풀이 */
    makeTeam(0);
    
    /* 출력 */
    cout << ability_diff << '\n';
}
