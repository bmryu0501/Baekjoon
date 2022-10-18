#include <iostream>

using namespace std;

/* condition */
#define MAX_K 10000
#define MAX_N 1000000

/* variables */
long long K, N;
long long arr[MAX_K];
long long low, mid, high;
long long ans = 0;

/* functions */
bool isPossible(long long N, long long K, long long length, long long arr[]) {
    int cnt = 0;
    for(int i=0;i<K;i++) {
        cnt += arr[i]/length;
        if(cnt >= N) return true;
    }
    return false;
}

int max(long long arr[]) {
    int ret = 0;
    for(int i=0;i<K;i++) if (ret < arr[i]) ret = arr[i];
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> K >> N;

    for(int i=0;i<K;i++) {
        cin >> arr[i];
    }

    /* solving */
    low = 1;
    high = max(arr);
    mid = (low + high) / 2;

    while(low <= high) {
        //cout << "[high] " << high << "\n[low] " << low << "\n[mid] " << mid << '\n';
        if(isPossible(N, K, mid, arr)) {
            if(ans < mid) ans = mid;
            low = mid+1;
        } else {
            high = mid-1;   
        }
        mid = (low + high) / 2;
    }

    /* output */
    cout << ans << '\n';
}