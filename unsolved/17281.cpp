#include <iostream>
#include <cstring>

#define MAX_N 50

using namespace std;

int N;
int arr[9][MAX_N];
bool roo[3];

int answer = 0;

int main() {
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<9;j++) cin >> arr[i][j];

    for(int i=0;i<N;i++) {
        int tmp = arr[i][0];
        arr[i][0] = arr[i][3];
        arr[i][3] = tmp;
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<9;j++) cout << arr[i][j] << ' ';
        cout << "\n";
    }

    int out, inning, score;
    int player;
    int result;
    for(int i=0;i<9;i++) {
        inning = 0;
        score = 0;
        player = i;
        while(inning < N) {
            out = 0;
            memset(roo, 0, sizeof(roo));
            while(out < 3) {
                result = arr[inning][player++];
                player %= 9;
                if(result == 0) out++;
                else if(result == 4) {
                    score++;
                    for(int r=0;r<3;r++) {
                        if(roo[r]) score++;
                        roo[r] = 0;
                    }
                } else {
                    for(int r=2;r>=0;r++) {
                        roo[r] = 0;
                        if(r+result>=3) score++;
                        else roo[r+result] = 1;
                    }
                    roo[result-1] = 1;
                }
            }
            inning++;
        }
        if(answer < score) answer = score;
    }

    cout << answer;

    return 0;
}