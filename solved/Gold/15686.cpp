#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#ifdef BOJ
#define DEBUG 0
#else
#define DEBUG 1
#endif

#define MAX_N 52
#define MAX_M 13
#define MAX_HOME MAX_N+MAX_N
#define MAX_CHICKEN MAX_M

#define abs(x)  ((x)>0?(x):-(x))

typedef struct Point {
    int y, x;
} Point;

int N, M;
int arr[MAX_N][MAX_N];
vector<Point> chicken, home;
int n_home, n_chicken;
int answer = 21e8;
int dist[MAX_HOME][MAX_CHICKEN];
vector<int> chosen;

int getSum()
{
    int ret = 0;
    for(int i=0;i<n_home;++i)
    {
        Point* h = &home[i];
        int min_val = 21e8;

        for(int j=0;j<chosen.size();++j)
        {
            min_val = min(min_val, dist[i][chosen[j]]);
        }

        ret += min_val;
    }
    return ret;
}

void go(int cnt, int idx)
{
    if(cnt == M)
    {
        answer = min(answer, getSum());
#if DEBUG
cout << "{";
for(int i=0;i<chosen.size();++i) cout << chosen[i] << ", ";
cout << "} " << answer << "\n";
#endif
        return;
    }

    for(int i=idx+1;i<n_chicken;++i)
    {
        chosen.push_back(i);
        go(cnt+1, i);
        chosen.pop_back();
    }
}

int main()
{
#if DEBUG
freopen("input.txt", "r", stdin);
#endif
    cin >> N >> M;
    for(int i=0;i<N;++i) for(int j=0;j<N;++j)
    {
        cin >> arr[i][j];
        switch(arr[i][j])
        {
            case 1:
                home.push_back({i, j});
                break;
            case 2:
                chicken.push_back({i, j});
                break;
        }
    }

    n_home = home.size();
    n_chicken = chicken.size();

    for(int i=0;i<n_home;++i) for(int j=0;j<n_chicken;++j)
        dist[i][j] = abs(home[i].y - chicken[j].y) + abs(home[i].x - chicken[j].x);
#if DEBUG
    for(int i=0;i<n_home;++i) {
        for(int j=0;j<n_chicken;++j) printf("%02d ", dist[i][j]);
        cout << "\n";
    }
#endif

    go(0, -1);

    cout << answer;

    return 0;
}