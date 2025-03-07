#include <iostream>

#ifdef BOJ
#define DEBUG 0
#else
#define DEBUG 1
#endif

using namespace std;

#define MAX_N 51

int N;
int arr[MAX_N];
int cnt[MAX_N];

int isVisible(long long a, long long b)
{
    for(int i=a+1;i<b;++i)
    {
        if(arr[a]>arr[b]) {
            if((arr[i]-arr[b])*(b-a) >= ((arr[a]-arr[b])*(b-i))) return 0;
        } else {
            if((arr[i]-arr[a])*(b-a) >= ((arr[b]-arr[a])*(i-a))) return 0;
        }
    }

    return 1;
}

int main()
{
#if DEBUG
freopen("input.txt", "r", stdin);
#endif
    cin >> N;
    for(int i=0;i<N;++i) cin >> arr[i];

    for(int i=0;i<N;++i) for(int j=i+1;j<N;++j)
    {
        if(i == j) continue;
        if(isVisible(i, j))
        {
            cnt[i]++;
            cnt[j]++;
#if DEBUG
cout << i << "->" << j << "\n";
        }
else {
    cout << i << "->" << j << "X\n";
#endif
        }
    }

    int max_idx = 0;
    for(int i=1;i<N;++i) {
        if(cnt[max_idx] < cnt[i]) max_idx = i;
    }

#if DEBUG
for(int i=0;i<N;++i) printf("%2d ", i);
cout << "\n";
for(int i=0;i<N;++i) printf("%2d ", cnt[i]);
cout << "\n";
#endif

    cout << cnt[max_idx];

    return 0;
}