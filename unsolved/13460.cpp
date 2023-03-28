#include <iostream>

#define MAX_N 10
#define MAX_M 10

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Node{
    int y, x;
};

int N, M;
char arr[MAX_N][MAX_M+1];
Node hole;
int answer = 11;

bool inRange(Node ball) {
    return ball.y >= 0 && ball.y < N && ball.x >= 0 && ball.x < M;
}

void printDebug(Node red, Node blue) {
    cout << '\n';
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(i == red.y && j == red.x) cout << 'R';
            else if(i == blue.y && j == blue.x) cout << 'B';
            else cout << arr[i][j];
        }
        cout << '\n';
    }
    char t;
    cin >> t;
}

void dfs(int level, Node red, Node blue) {
    if(level == 11 || answer <= level) return;

    

    for(int d=0;d<4;d++) {
        Node nr = red;
        Node nb = blue;
        int mover= 0;
        int moveb= 0;
        bool goner= false;
        bool goneb= false;

        while(inRange(nr) && arr[nr.y][nr.x] == '.'){
            nr.y += dy[d];
            nr.x += dx[d];
            if(inRange(nr) && arr[nr.y][nr.x] == 'O') {
                goner = true;
                break;
            }
            ++mover;
        }

        while(inRange(nb) && arr[nb.y][nb.x] == '.') {
            nb.y += dy[d];
            nb.x += dx[d];
            if(inRange(nb) && arr[nb.y][nr.x] == 'O') {
                goneb = true;
                break;
            }
            ++moveb;
        }

        nr.y -= dy[d];
        nr.x -= dx[d];
        nb.y -= dy[d];
        nb.x -= dx[d];

        if(nr.y == nb.y && nr.x == nb.x) {
            if(mover < moveb) {
                nr.y -= dy[d];
                nr.x -= dx[d];
            } else {
                nb.y -= dy[d];
                nb.x -= dx[d];
            }
        }

        if(goner) {
            if(goneb) continue;
            if(answer > level) answer = level;
            continue;
        }

        if(nr.y == red.y && nr.x == red.x && nb.y == blue.y && nb.x == blue.x) continue;
        dfs(level+1, nr, nb);
    }
}

int main() {
    cin >> N >> M;
    Node red, blue;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        for(int j=0;j<M;j++) {
            if(arr[i][j] == 'B') blue = {i, j};
            else if(arr[i][j] == 'R') red = {i, j};
            else if(arr[i][j] == 'O') hole = {i, j};
        }
    }

    arr[red.y][red.x] = '.';
    arr[blue.y][blue.x] = '.';
    dfs(1, red, blue);

    if(answer == 11) cout << -1;
    else cout << answer;

    return 0;
}