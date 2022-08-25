#include <iostream>

using namespace std;

int main() {
    int N, cnt = 0;

    scanf("%d", &N);

    
    while(N % 5 > 0) { //5의 배수가 아니면 반복
        N -= 3; // 3만큼 빼고 count
        cnt++;
        if(N == 0) { // 3씩 빼서 나누어 떨어진 경우 답 출력 후 종료
            printf("%d\n", cnt);
            return 0;
        }
        else if(N < 3) { // 3씩 뺐는데 3보다 작아 3 또는 5로 만들 수 없는 경우
            printf("-1\n"); // -1 출력 후 종료
            return 0;
        }
    }

    printf("%d\n", cnt + N/5); // 3씩 뺀 후 5의 배수가 된 N을 5로 나눠 정답 출력
    return 0;
}