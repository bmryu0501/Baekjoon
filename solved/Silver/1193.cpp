#include <iostream>

using namespace std;

int main() {
    int X, floor;

    scanf("%d", &X);

    //* 풀이과정 */
    // floor는 대각선 방향으로 N번째임을 나타나는 변수
    // 주어진 표는 각 floor마다 존재하는 분수의 개수가 계차수열로 존재
    // 아래의 loop는 floor = 1 부터 시작해 X가 어디 floor의 몇번째를 가리키는지 계산
    // floor 단계의 X번째 분수가 됨
    for(floor = 1; X > floor; X -= floor++) {}

    // floor가 짝수일 때 X번째 분수는 X / (floor - X + 1) 이 되며
    // floor가 홀수일 때 X번째 분수는 (floor - X + 1) / X 이 됨
    if(floor % 2 == 0) printf("%d/%d\n", X, floor - X + 1);
    else printf("%d/%d\n", floor - X + 1, X);
}