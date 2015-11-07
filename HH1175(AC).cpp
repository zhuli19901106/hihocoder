// A simple problem, but you can't be too careful with it.
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

const int MOD = 142857;
const int N = 100000;
vector<unordered_set<int> > e;
queue<int> q;
int n, m, k;
int ind[N];
int res[N];

int main()
{
    int i;
    int x, y;
    
    scanf("%d%d%d", &n, &m, &k);
    memset(res, 0, sizeof(res));
    for (i = 0; i < k; ++i) {
        scanf("%d", &x);
        --x;
        res[x] = (res[x] + 1) % MOD;
    }
    
    e.resize(n);
    memset(ind, 0, sizeof(ind));
    for (i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        --x;
        --y;
        e[x].insert(y);
        ++ind[y];
    }

    for (i = 0; i < n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        i = q.front();
        q.pop();
        if (ind[i] > 0) {
            continue;
        }
        
        auto eit = e[i].begin();
        while(eit != e[i].end()) {
            --ind[*eit];
            res[*eit] = (res[*eit] + res[i]) % MOD;
            q.push(*eit);
            e[i].erase(*eit);
            eit = e[i].begin();
        }
    }
    
    int ans = 0;
    for (i = 0; i < n; ++i) {
        ans = (ans + res[i]) % MOD;
    }
    printf("%d\n", ans);
    
    return 0;
}