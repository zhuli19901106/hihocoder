#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int d[3];
int c[3];
const int N = 20000;
char s[N + 1];
int hs[256];

bool equal()
{
    static int d1[3];
    int i;
    for (i = 0; i < 3; ++i) {
        d1[i] = abs(c[i] - c[(i + 1) % 3]);
    }
    sort(d1, d1 + 3);
    for (i = 0; i < 3; ++i) {
        if (d[i] != d1[i]) {
            return false;
        }
    }
    return true;
}

void solve()
{
    int i, j;
    int ans = 0;
    int sum = 0;
    
    for (i = 0; s[i]; ++i) {
        j = hs[s[i]];
        ++sum;
        ans = max(ans, sum);
        ++c[j];
        if (equal()) {
            memset(c, 0, sizeof(c));
            sum = 0;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int i = 0;
    hs['R'] = i++;
    hs['Y'] = i++;
    hs['B'] = i++;
    
    scanf("%d%d%d", &d[0], &d[1], &d[2]);
    sort(d, d + 3);
    scanf("%s", s);
    solve();
    
    return 0;
}