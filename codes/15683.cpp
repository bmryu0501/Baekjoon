#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/* condition */
#define MAX_N 8
#define MAX_M 8
#define MAX_CAMERA 8

/* custom */
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/* variables */
int N, M;
vector<vector <int>> v;
vector<pair<int, int>> arr_camera;
int num_camera = 0;

/* functions */
int min(int a, int b) {
    return a<b?a:b;
}

int count_zero(vector<vector<int>> v) {
    int cnt = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(v[i][j]==0)
                cnt++;

    return cnt;
}

int fill_area(int camera_num, vector<vector<int>> v) {
    cout << '[' << camera_num << ']' << '\n'; 

    int x_origin = arr_camera[camera_num].first;
    int y_origin = arr_camera[camera_num].second;

    int min_blind_spot = MAX_N * MAX_M;

    if(camera_num > num_camera) {
        return count_zero(v);
    }

    int x = x_origin;
    int y = y_origin;

    switch (v[x_origin][y_origin]) {
        case 1:
            for(int i=0;i<4;i++) {
                vector<vector<int>> v_tmp;
                copy(v.begin(), v.end(), v_tmp.begin());

                while(x >= 0 && x < N && y >= 0 && y < M) {
                    x+=dx[i];
                    y+=dy[i];

                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }

                int blind_spot = fill_area(camera_num+1, v_tmp);
                if(blind_spot < min_blind_spot) min_blind_spot = blind_spot;
            }
            return min_blind_spot;
        case 2:
            for(int i=0;i<2;i++) {
                vector<vector<int>> v_tmp;
                copy(v.begin(), v.end(), v_tmp.begin());

                while(x >= 0 && x < N && y >= 0 && y < M && v[x][y] != 6) {
                    x+=dx[i];
                    y+=dx[i];
                    
                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }

                x = x_origin;
                y = y_origin;
                while(x >= 0 && x < N && y >= 0 && y < M && v[x][y] != 6) {
                    x+=dx[i+2];
                    y+=dx[i+2];
                    
                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }

                int blind_spot = fill_area(camera_num+1, v_tmp);
                if (blind_spot < min_blind_spot) min_blind_spot = blind_spot;
            }
            return min_blind_spot;
        case 3:
            for(int i=0;i<4;i++) {
                vector<vector<int>> v_tmp;
                copy(v.begin(), v.end(), v_tmp.begin());

                while(x >= 0 && x < N && y >= 0 && y < M) {
                    x+=dx[i];
                    y+=dy[i];

                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }

                x = x_origin;
                y = y_origin;
                while(x >= 0 && x < N && y >= 0 && y < M && v[x][y] != 6) {
                    x+=dx[(i+1)%4];
                    y+=dx[(i+1)%4];
                    
                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }

                int blind_spot = fill_area(camera_num+1, v_tmp);
                if(blind_spot < min_blind_spot) min_blind_spot = blind_spot;
            }
            return min_blind_spot;
        case 4:
            for(int i=0;i<4;i++) {
                vector<vector<int>> v_tmp;
                copy(v.begin(), v.end(), v_tmp.begin());

                while(x >= 0 && x < N && y >= 0 && y < M) {
                    x+=dx[i];
                    y+=dy[i];

                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }

                x = x_origin;
                y = y_origin;
                while(x >= 0 && x < N && y >= 0 && y < M && v[x][y] != 6) {
                    x+=dx[(i+1)%4];
                    y+=dx[(i+1)%4];
                    
                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }

                x = x_origin;
                y = y_origin;
                while(x >= 0 && x < N && y >= 0 && y < M && v[x][y] != 6) {
                    x+=dx[(i+2)%4];
                    y+=dx[(i+2)%4];
                    
                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }

                int blind_spot = fill_area(camera_num+1, v_tmp);
                if(blind_spot < min_blind_spot) min_blind_spot = blind_spot;
            }
            return min_blind_spot;
        case 5:
            vector<vector<int>> v_tmp;
            copy(v.begin(), v.end(), v_tmp.begin());

            for(int i=0;i<4;i++) {
                while(x >= 0 && x < N && y >= 0 && y < M) {
                    x+=dx[i];
                    y+=dy[i];

                    if(v[x][y] == 6) break;
                    if(v[x][y] == 0) v[x][y] = -1;
                }
            }

            int blind_spot = fill_area(camera_num+1, v_tmp);
            if(blind_spot < min_blind_spot) min_blind_spot = blind_spot;

            return min_blind_spot;
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> N >> M;
    v.resize(N, vector<int>(M, 0));

    cout << v.size() << '\n';

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

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    /* output */
    cout << fill_area(0, v) << '\n';

}