#include <iostream>
//#include <algorithm>

/* STL
#include <vector> // https://blockdmask.tistory.com/70
#include <list>
#include <map> // https://blockdmask.tistory.com/87
#include <set>
#include <stack>
#include <queue>
*/

/* math.h
#define _USE_MATH_DEFINES // need this to use math defines
#include <math.h>
*/

//#include <cstring>
/* memset
    // Since byte-by-byte, int should be 0 or -1
    #include <cstring>
    memset(arr, 0, sizeof(arr));
*/

//#include <climits>
/* <climits>
CHAR_BIT    char number of bit 
SCHAR_MIN   signed char
SCHAR_MAX   signed char
UCHAR_MAX   unsigned char
CHAR_MIN    char
CHAR_MAX    char
MB_LEN_MAX  multi-byte char max bite
SHRT_MIN    short int
SHRT_MAX    short int
USHRT_MAX   unsigned short int
INT_MIN     int
INT_MAX     int
UINT_MAX    unsigned int
LONG_MIN    long int
LONG_MAX    long int
ULONG_MAX   unsigned long int
*/

/* customized */ /*
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dx8[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy8[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
*/

using namespace std;

/* condition */
#define MAX_K 10000
#define MAX_N 1000000

/* variables */
int K, N;
int arr[MAX_K];
int low, mid, high;
int ans = 0;

/* functions */
bool isPossible(int N, int K, int length, int arr[]) {
    int cnt = 0;
    for(int i=0;i<K;i++) {
        cnt += arr[i]/length;
        if(cnt >= N) return true;
    }
    return false;
}

int max(int arr[]) {
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
    low = 0;
    high = max(arr);

    while(1) {
        mid = (low + high) / 2;
    }

    /* output */
}