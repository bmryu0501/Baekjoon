/*************************************************
* 02960 에라토스테네스의 체
* 수학, 구현, 정수론, 소수 판정, 에라토스테네스의 체
**************************************************/



#include <iostream>
#include <cstring>

using namespace std;

#define MAX_K 1000
#define MAX_N 1000

bool arr[MAX_N+1]; // if erased arr[i] == true
int N, K;
int cnt = 0;

int getP() {
    for (int i=2;i<=N;i++)
        if(!arr[i])
            return i;
    return -1; // error
}

int eraseNum(int P) {
    if(arr[P]) return 0;
    arr[P] = true;
    return 1;
}

int main() {
    /* init */
    memset(arr, false, sizeof(arr));
    arr[0] = true;
    arr[1] = true;

    /* input */
    cin >> N >> K; // 7 3

    int P;

    /* solving */
    while (cnt < K) {
        P = getP();
        int adder = P;
        while(P <= N && cnt < K) {
            cnt += eraseNum(P);
            if(cnt >= K) break;
            P += adder;
            /*
            cout << "cnt  : " << cnt << endl;
            cout << "P    : " << P << endl;
            cout << "adder: " << adder << endl << endl;
            */
        }
    }

    /* output */
    cout << P;
}