#include <iostream>

#include <math.h>

using namespace std;    

int main() {
    int T, x1, y1, r1, x2, y2, r2;
    float dist;

    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

        dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        if(dist == 0) { // ���ɿ�
            if(r1 == r2) printf("-1\n"); // ���� ��
            else printf("0\n"); // ���ɿ������� ������ �ٸ�
        } else if(dist > r1 + r2)
            printf("0\n"); // �ܺο� ����
        else if(dist == r1 + r2 || dist + r1 == r2 || dist + r2 == r1)
            printf("1\n"); // ����, ����
        else if(dist + r1 < r2 || dist + r2 < r1)
            printf("0\n"); // ���ο� ����
        else printf("2\n");
    }
}