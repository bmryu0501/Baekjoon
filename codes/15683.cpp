#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/* condition */
#define MAX_N 8
#define MAX_M 8
#define MAX_CAMERA 8

/* custom */
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

/* variables */
int N, M;
vector<vector <int>> v;
vector<pair<int, int>> arr_camera;
int num_camera = 0;

/* functions */
int min(int a, int b) {
    return a<b?a:b;
}

int fill_area(int n, int m, int camera_num, vector<vector<int>> v) {
    int x_origin = arr_camera[camera_num].first;
    int y_origin = arr_camera[camera_num].second;
    if(camera_num > num_camera) {
        int cnt = 0;

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++){
                if(v[i][j] == 0) cnt++;
            }

            return cnt;
        }
    }

    switch (v[x_origin][y_origin]) {
        int x_curr = x_origin;
        int y_curr = y_origin;

        case 1:
            for(int i=0;i<4;i++) {
                vector<vector<int>> v_tmp;
                copy(v.begin(), v.end(), v_tmp.begin());
                while(x_curr >= 0 && x_curr < N && y_curr >= 0 && y_curr < M && v[x_curr][y_curr] != 6) {
                    x_curr+=dx[i];
                    y_curr+=dy[i];

                    if(v[x_curr][y_curr] == 0) {
                        
                    }
                        
                }
            }
        case 2:
        case 3:
        case 4:
        case 5:
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> N >> M;
    v.resize(N, vector<int>(M, 0));

    /* solving */
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++){
            cin >> v[i][j];
            if (v[i][j] > 0 && v[i][j] < 6) {
                arr_camera.push_back(make_pair(i, j));
                num_camera++;
            }
        }
    }


    /* output */
}