#include <iostream>

using namespace std;

#define MAX_N 203

int N;
int arr[MAX_N], dp[MAX_N];
int cnt;

int LIS(int idx, int len)
{
#ifndef BOJ
cout << idx << " ";
#endif
    if(dp[idx] && dp[idx] >= len) return dp[idx];

    cnt = max(cnt, len);

    for(int i=idx+1;i<=N;++i) {
        if(arr[i] > arr[idx]) {
            dp[idx] = LIS(i, len+1)-1;
        }
    }

    return dp[idx] = len;
}

int main()
{
#ifndef BOJ
    freopen("input.txt", "r", stdin);
#endif

    cin >> N;

    for(int i=1;i<=N;++i)
    {
        cin >> arr[i];
    }

    for(int i=1;i<=N;++i) LIS(i, 1);

#ifndef BOJ
    printf("\n[Index] ");
    for(int i=1;i<=N;++i) printf("%2d ", i);
    printf("\n[Num]   ");
    for(int i=1;i<=N;++i) printf("%2d ", arr[i]);
    printf("\n[Len]   ");
    for(int i=1;i<=N;++i) printf("%2d ", dp[i]);
    printf("\n");
#endif

    cout << N-cnt;
}