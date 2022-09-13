#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

/* condition */
#define MIN_N 3
#define MAX_N 999

/* variables */
int N, K;
int x, y;
int x_center, y_center;
int level = 1;

int arr[MAX_N][MAX_N];

//direction {N,  E, S,  W}
int dx[4] = {-1, 0, 1,  0};
int dy[4] = {0,  1, 0, -1};
int direction = 0;

/* functions */

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> N >> K;

    x_center = N/2;
    y_center = N/2;
    x = N/2;
    y = N/2;

    /* solving */
    for(int i=1;i<=N*N;i++) {
        arr[x][y] = i;

        
    }

    /* output */
}