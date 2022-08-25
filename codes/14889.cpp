/************************************
 * Author: Byeongmin Ryoo           *
 * Blog: https://velog.io/@kkoala   *
 * Contact: bmformail@naver.com     *
 ************************************/

#include <iostream>
#include <vector>

using namespace std;

/* ���� */
#define MAXINT 2147483647
#define MAX 20

/* ���� */
int N;
int arr[MAX][MAX];
int ability_diff = MAXINT; // �� �ɷ�ġ ����
int ability_start, ability_link;
vector<int> start, link;

/* �Լ� */
// ���� ��ȯ
int abs(int a) {
    return (a < 0) ? (a * -1) : a;
}

void makeTeam(int idx) {
    // ��� ����
    if(idx == N) {
        if(start.size() == N/2 && link.size() == N/2) { // �� ���� ���� ���� ��            
            // ability ���
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

    // ���
    // start ������ �� ��
    start.push_back(idx);
    makeTeam(idx+1);
    start.pop_back();

    // link ������ �� ��
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

    /* �Է� */
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    /* Ǯ�� */
    makeTeam(0);
    
    /* ��� */
    cout << ability_diff << '\n';
}
