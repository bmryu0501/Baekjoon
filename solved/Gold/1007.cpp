#include <iostream>
#include <cfloat>
#include <math.h>
#include <cstring>

#ifdef BOJ
#define DEBUG 0
#else
#define DEBUG 1
#endif

using namespace std;

#define MAX_N 21

typedef struct Point {
    int y, x;
} Point;

int T, N;
Point p[MAX_N];
int visited[MAX_N];
double answer;

void dfs(int cnt, int idx)
{
    if(N-idx+cnt < N/2) return;
    if(cnt == N/2)
    {
#if DEBUG
for(int i=0;i<N;++i) printf("%2d ", visited[i]);
cout << "\n";
#endif
        double y = 0;
        double x = 0;
        for(int i=0;i<N;++i)
        {
            y += p[i].y * visited[i];
            x += p[i].x * visited[i];
        }
#if DEBUG
cout << "{" << y << ", " << x << "}\n";
#endif
        answer = min(answer, sqrt(y*y + x*x));
    }

    for(int i=idx;i<N;++i)
    {
        if(visited[i] == 1) continue;
        visited[i] = 1;
        dfs(cnt+1, i+1);
        visited[i] = -1;
    }
}

int main()
{
#if DEBUG
freopen("input.txt", "r", stdin);
#endif
    cin >> T;
    while(T--)
    {
        answer = DBL_MAX;
        memset(visited, -1, sizeof(visited));

        cin >> N;
        for(int i=0;i<N;++i)
        {
            cin >> p[i].y >> p[i].x;
        }

        dfs(0, 0);

        printf("%.6f\n", answer);
    }

    return 0;
}