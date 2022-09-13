#include <iostream>
#include <algorithm>

#include <vector> // https://blockdmask.tistory.com/70
#include <list>
#include <map> // https://blockdmask.tistory.com/87
#include <set>
#include <stack>
#include <queue>

#define _USE_MATH_DEFINES // need this to use math defines
#include <math.h>

#include <cstring>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dx8[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy8[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

using namespace std;

/* condition */

/* variables */

/* functions */

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i < 100; i += 2) {
        cout << "[" << i << "] " << i/2 << endl;
    }
}