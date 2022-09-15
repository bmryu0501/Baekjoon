#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

/* condition */
#define MIN_N 3
#define MAX_N 999

/* variables */
int N, K;

int arr[MAX_N][MAX_N];

int x, y;
int x_center, y_center;
int x_result, y_result;
int cnt = 0;
int block_size = 1;

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
        cnt++;

        // cout << '[' << i << "] (" << x << ", " << y << ")\n";
        
        if(i == K) {
            x_result = x;
            y_result = y;
        }

        x += dx[direction];
        y += dy[direction];

        if(cnt == block_size) {
            cnt = 0;
            if(direction % 2 == 1) block_size++;
            direction++;
            direction %= 4;
        }

    }

    /* output */
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    cout << x_result+1 << ' ' << y_result+1 << '\n';
}