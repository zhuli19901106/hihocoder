#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;

const int N = 100000;
int d[N];
vector<unordered_set<int> > e;
int n;

void DFS(int idx, int dist)
{
    d[idx] = dist;
    
    for (auto it = e[idx].begin(); it != e[idx].end(); ++it) {
        if (d[*it] != -1) {
            continue;
        }
        DFS(*it, dist + 1);
    }
}

int solve()
{
    // Start searching from an arbitrary vertex.
    memset(d, -1, sizeof(d));
    DFS(0, 0);
    int maxd, maxi;
    int i;
    
    maxd = maxi = -1;
    for (i = 0; i < n; ++i) {
        if (d[i] > maxd) {
            maxd = d[i];
            maxi = i;
        }
    }
    
    // Start searching from the farthest vertex.
    memset(d, -1, sizeof(d));
    DFS(maxi, 0);
    
    maxd = -1;
    for (i = 0; i < n; ++i) {
        maxd = max(maxd, d[i]);
    }
    return maxd;
}

int main()
{
    int x, y;
    int i;
    
    scanf("%d", &n);
    e.resize(n);
    for (i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        --x, --y;
        e[x].insert(y);
        e[y].insert(x);
    }
    printf("%d\n", solve());
    
    return 0;
}