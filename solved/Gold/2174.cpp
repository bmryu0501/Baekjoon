#include <iostream>
#include <vector>

using namespace std;

/* condition */
#define MAX_A 100
#define MAX_B 100
#define MAX_N 100

// {N, E, S, W}
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/* variables */
int A, B, N, M;

struct robot{
    int x = 0;
    int y = 0;
    int direction = 0;
};

bool flag = false;

vector<robot> robots;

/* functions */
int get_direction(char c) {
    if (c == 'N') return 0;
    else if (c == 'E') return 1;
    else if (c == 'S') return 2;
    else if (c == 'W') return 3;
    return -1;
}

bool check_crash(int robot_number) {
    int x = robots[robot_number].x;
    int y = robots[robot_number].y;
    
    if(x < 1 || x > A || y < 1 || y > B) {
        cout << "Robot " << robot_number+1 << " crashes into the wall\n";
        return true;
    }

    for(int i=0;i<robots.size();i++){
        if(i == robot_number) continue;
        if(robots[i].x == robots[robot_number].x && robots[i].y == robots[robot_number].y) {
            cout << "Robot " << robot_number+1 << " crashes into robot " << i+1 << '\n';
            return true;
        }
    }
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* init */

    /* input */
    cin >> A >> B >> N >> M;

    /* solving */
    for(int i=0;i<N;i++) {
        robot rb;
        char tmp;
        cin >> rb.x >> rb.y >> tmp;
        rb.direction = get_direction(tmp);

        robots.push_back(rb);
    }

    for(int i=0;i<M;i++) {
        int robot_number;
        char operation;
        int times;
        cin >> robot_number >> operation >> times;
        robot_number--;

        if(operation == 'L') robots[robot_number].direction = (4 + (robots[robot_number].direction - times) % 4) % 4;
        else if (operation == 'R') robots[robot_number].direction = (robots[robot_number].direction + times) % 4;
        else {
            for(int j=0;j<times;j++) {
                robots[robot_number].x += dx[robots[robot_number].direction];
                robots[robot_number].y += dy[robots[robot_number].direction];
                if(flag = check_crash(robot_number)) {
                    break;
                }
            }
        }
        //cout << "Robot [" << robot_number+1 << "] (" << robots[robot_number].x << ", " << robots[robot_number].y << ") " << robots[robot_number].direction << '\n';
        if(flag) break;
    }

    /* output */
    if(!flag) cout << "OK";
}