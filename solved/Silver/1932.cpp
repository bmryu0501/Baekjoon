#include <iostream>
#include <vector>

using namespace std;

/* ���� */

/* ���� */
int n, tmp;
vector<int> v;

/* �Լ� */

int main() {
    /* Fast cin cout */
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*****************/

    /* �Է� */
    cin >> n;
    for(int i = 0; i < n*(n+1)/2; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    /* Ǯ�� */
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            v[i*(i-1)/2 + j] += max(v[i*(i+1)/2 + j], v[i*(i+1)/2 + j + 1]);
        }
    }

    /* ��� */
    cout << v[0];
}