#include <cstdio>
#include <cstring>
using namespace std;

const int UNKNOWN = -1;
const int MINE = -2;
const int NOT_MINE = -3;
const int N = 15;
const int d[8][2] = {
    {-1, -1}, 
    {-1,  0}, 
    {-1, +1}, 
    { 0, -1}, 
    { 0, +1}, 
    {+1, -1}, 
    {+1,  0}, 
    {+1, +1}
};

int n, m;
int a[N][N];
int b[N][N];
bool progress;
int mine_count, not_mine_count;

bool inbound(int x, int y)
{
    return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
}

void set(int x, int y, int val)
{
    int i;
    int x1, y1;
    for (i = 0; i < 8; ++i) {
        x1 = x + d[i][0];
        y1 = y + d[i][1];
        if (!inbound(x1, y1) || a[x1][y1] != UNKNOWN) {
            continue;
        }
        a[x1][y1] = val;
    }
}

void trySolve(int x, int y)
{
    int i;
    int x1, y1;
    int mc, uc;
    
    mc = uc = 0;
    for (i = 0; i < 8; ++i) {
        x1 = x + d[i][0];
        y1 = y + d[i][1];
        if (!inbound(x1, y1)) {
            continue;
        }
        if (a[x1][y1] == MINE) {
            ++mc;
        } else if (a[x1][y1] == UNKNOWN) {
            ++uc;
        }
    }
    if (uc == 0) {
        b[x][y] = 1;
        return;
    }
    if (a[x][y] - mc == 0 && uc > 0) {
        set(x, y, NOT_MINE);
        not_mine_count += uc;
        progress = true;
    } else if (uc == a[x][y] - mc && uc > 0) {
        set(x, y, MINE);
        mine_count += uc;
        progress = true;
    }
}

int main()
{
    int cn, ci;
    int i, j;
    
    scanf("%d", &cn);
    for (ci = 0; ci < cn; ++ci) {
        scanf("%d%d", &n, &m);
        memset(b, 0, sizeof(b));
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        mine_count = not_mine_count = 0;
        do {
            progress = false;
            for (i = 0; i < n; ++i) {
                for (j = 0; j < m; ++j) {
                    if (a[i][j] < 0 || b[i][j]) {
                        continue;
                    }
                    trySolve(i, j);
                }
            }
        } while (progress);
        printf("%d %d\n", mine_count, not_mine_count);
    }
    
    return 0;
}