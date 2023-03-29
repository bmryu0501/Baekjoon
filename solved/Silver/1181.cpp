#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    if(a.length() == b.length()) // ���̰� ������ ������
        return a < b;
    else return a.length() < b.length(); // ���̰� ª�� ������
}

int main() {
    int N;
    string tmp;
    vector<string> arr;

    /* �Է� */
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    /* Ǯ�� */
    sort(arr.begin(), arr.end(), comp); // ����
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); // �ߺ� ����

    /* ��� */
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\n";
    }
}