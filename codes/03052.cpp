#include <iostream>

using namespace std;

int main() {
    int arr[42] = {0, }, a, cnt;
    cnt = 0;
    for(int i = 0; i < 10; i++) {
        scanf("%d", &a);
        arr[a%42]++;
    }
    for(int i = 0; i < 42; i++) if(arr[i] > 0) cnt++;
    printf("%d\n", cnt);
}