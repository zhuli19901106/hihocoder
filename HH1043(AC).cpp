#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 100000;
int dp[M + 1];

const int N = 500;
int w[N];
int p[N];

int n, m;
int ans;

int main()
{
    int i, j;
    
    while (scanf("%d%d", &n, &m) == 2) {
        for (i = 0; i < n; ++i) {
            scanf("%d%d", &w[i], &p[i]);
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (i = 0; i < n; ++i) {
            for (j = w[i]; j <= m; ++j) {
                if (dp[j - w[i]] == -1) {
                    continue;
                }
                dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
            }
        }
        ans = 0;
        for (i = m; i >= 0; --i) {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}