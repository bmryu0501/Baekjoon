#include <iostream>
using namespace std;

#define MAX_H 300
#define MAX_W 300

int H, W, X, Y;

int arr[MAX_H*2][MAX_W*2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W >> X >> Y;
    for(int i=0;i<H+X;i++)for(int j=0;j<W+Y;j++) {
        if(i < H && i >= X && j < W && j >= Y) {
            int t;
            cin >> t;
            arr[i][j] = t - arr[i-X][j-Y];
        } else {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}