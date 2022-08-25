#include <iostream>
#include <cstring>

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
#define MAX_N 300
#define MAX_Q 100000

/* variables */
int N, Q;
int x1, y1, x2, y2;
int arr[MAX_N+1][MAX_N+1];
int dp[MAX_N+1][MAX_N+1][11];

/* functions */
int count_dp(int x1, int y1, int x2, int y2) {
    int ret = 0;
    for(int i=1;i<=10;i++) {
        if(dp[x2][y2][i] - dp[x1-1][y2][i] - dp[x2][y1-1][i] + dp[x1-1][y1-1][i] > 0) ret++;
    }
    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */
    memset(arr, 0, sizeof(arr));

    /* solve */
    cin >> N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> arr[i][j];
            for(int k=1;k<=10;k++) {
                dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
            }
            dp[i][j][arr[i][j]]++;
        }
    }

    cin >> Q;
    while(Q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << count_dp(x1, y1, x2, y2) << '\n';
    }
}