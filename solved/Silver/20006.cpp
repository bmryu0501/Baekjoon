#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

#define MAX_P 305
#define MAX_M 305
#define MAX_L 505
#define MAX_N 17

struct Player {
    int level;
    char name[MAX_N];

    bool operator<(const Player p) const {
        return strcmp(this->name, p.name) > 0 ? true : false;
    }
} players[MAX_P];

struct ComparePlayer {
    bool operator()(Player* a, Player* b) const {
        return strcmp(a->name, b->name) > 0;
    }
};

struct Room {
    int level;
    int cnt;
    priority_queue<Player*, vector<Player*>, ComparePlayer> pq;
} rooms[MAX_P];

int p, m;
int room_cnt;

int main() {
    cin >> p >> m;

    for(int i=1;i<=p;++i) {
        Player *player = &players[i];
        cin >> player->level >> player->name;

        for(int j=0;j<=room_cnt;++j)
        {
            Room *room = &rooms[j];
            if(room->level == 0)
            {
                room->level = player->level;
                room->pq.push(player);
                room->cnt++;
                room_cnt++;
                break;
            }

            if(room->cnt < m && room->level - 10 <= player->level && room->level + 10 >= player->level)
            {
                room->pq.push(player);
                room->cnt++;
                break;
            }
        }
    }

    for(int i=0;i<room_cnt;++i) {
        Room *room = &rooms[i];
        cout << ((room->cnt == m) ? "Started!\n" : "Waiting!\n");
        Player *player;
        while(!room->pq.empty()) {
            player = room->pq.top();
            room->pq.pop();
            cout << player->level << " " << player->name << "\n";
        }
    }

    return 0;
}