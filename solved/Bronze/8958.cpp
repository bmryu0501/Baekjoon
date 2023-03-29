#include <iostream>

using namespace std;

int main() {
    int N, cnt, score;
    char a;
    
    scanf("%d", &N);
    scanf("%c", &a);
    for(int i = 0; i < N; i++) {
        a = '\0';
        cnt = 0;
        score = 0;
        while(scanf("%c", &a) != EOF && a != '\n') {
            if (a == 'O') {
                cnt++;
                score += cnt;
            }
            else {
                cnt = 0;
            }
        }
        printf("%d\n", score);
    }
}