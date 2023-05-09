#include <iostream>
using namespace std;

#define MAX_SIZE 2000000
#define MAX_M 1000
#define MAX_N 1000

int target;
int A, B;

int datA[MAX_SIZE];
int datB[MAX_SIZE];

int arrA[MAX_M];
int arrB[MAX_N];

int main() {
    cin >> target >> A >> B;
    for(int i=0;i<A;i++) cin >> arrA[i];
    for(int i=0;i<B;i++) cin >> arrB[i];

    datA[0] = 1;
    datB[0] = 1;

    for(int i=0;i<A;i++) {
        int sum = arrA[i];
        datA[sum]++;
        for(int j=i+1;j<A+i;j++) {
            sum += arrA[j%A];
            datA[sum]++;
        }
        datA[sum] = 1;
    }
    for(int i=0;i<B;i++) {
        int sum = arrB[i];
        datB[sum]++;
        for(int j=i+1;j<B+i;j++) {
            sum += arrB[j%B];
            datB[sum]++;
        }
        datB[sum] = 1;
    }

    int ans = 0;
    for(int i=0;i<=target;i++) {
        ans += datA[i] * datB[target-i];
        //cout << "(" << i << ", " << target-i << ") " << datA[i] * datB[target-i] << '\n';
    }

    cout << ans;

    return 0;
}