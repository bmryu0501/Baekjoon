#include <iostream>

using namespace std;

int main() {
    int X, floor;

    scanf("%d", &X);

    //* Ǯ�̰��� */
    // floor�� �밢�� �������� N��°���� ��Ÿ���� ����
    // �־��� ǥ�� �� floor���� �����ϴ� �м��� ������ ���������� ����
    // �Ʒ��� loop�� floor = 1 ���� ������ X�� ��� floor�� ���°�� ����Ű���� ���
    // floor �ܰ��� X��° �м��� ��
    for(floor = 1; X > floor; X -= floor++) {}

    // floor�� ¦���� �� X��° �м��� X / (floor - X + 1) �� �Ǹ�
    // floor�� Ȧ���� �� X��° �м��� (floor - X + 1) / X �� ��
    if(floor % 2 == 0) printf("%d/%d\n", X, floor - X + 1);
    else printf("%d/%d\n", floor - X + 1, X);
}