#include <iostream>
#include <cmath>

using namespace std;

/* condition */
#define MAX_XY 1e12

/* variables */
long long x, y;
long long n = 0;
int ans = 0;

/* functions */

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> x >> y;

    /* solving */
    while(1) {
        if (n * (n+1) / 2 == x + y) {
            while(x > 0) {
                if(x >= n) {
                    x -= n;
                    ans++;
                }
                n--;
            }
            break;
        }
        else if (n * (n+1) / 2 > x + y) {
            ans = -1;
            break;
        }
        n++;
    }
    



    /* output */
    cout << ans << '\n';
}