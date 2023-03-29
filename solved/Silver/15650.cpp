#include <iostream>

using namespace std;

/* ���� */
#define MAX 8

/* ���� */
int N, M, output[MAX];
bool visited[MAX];

/* �Լ� */
void tracker(int count, int min) { // DFS�ϴ� �Լ�, count��° �������� �ǹ�
    if(count == M) { // M��ŭ output�� ���� ��� �� return
        for(int i = 0; i < M; i++) {
            cout << output[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = min; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true; // DFSó�� visited true
            output[count] = i + 1; // 1���� �����̱� ������ i+1
            tracker(count + 1, i); // ���� ���� ����
            visited[i] = false; // ���ư��� ���� visited false
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* �Է� */
    cin >> N >> M;

    /* Ǯ�� */
    tracker(0, 0);

    /* ��� */

}