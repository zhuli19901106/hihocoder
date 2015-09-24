#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef int in;
const in N = 10000;
vector<vector<in> > e;
vector<in> v;
in n, m;

bool solve()
{
    in i, j;
    queue<in> q;
    while (true) {
        for (i = 0; i < n; ++i) {
            if (v[i] == 0) {
                break;
            }
        }
        if (i == n) {
            break;
        }
        
        v[i] = 1;
        q.push(i);
        while (!q.empty()) {
            i = q.front();
            q.pop();
            for (j = 0; j < e[i].size(); ++j) {
                if (v[e[i][j]] == 0) {
                    v[e[i][j]] = 3 - v[i];
                    q.push(e[i][j]);
                } else if (v[e[i][j]] == v[i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

in main()
{
    in cn, ci;
    in i;
    in x, y;
    
    scanf("%d", &cn);
    for (ci = 0; ci < cn; ++ci) {
        scanf("%d%d", &n, &m);
        e.resize(n);
        v.resize(n, 0);
        for (i = 0; i < m; ++i) {
            scanf("%d%d", &x, &y);
            --x;
            --y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        printf(solve() ? "Correct\n" : "Wrong\n");
        e.clear();
        v.clear();
    }
    
    return 0;
}