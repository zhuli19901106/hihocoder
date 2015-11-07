#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 500;
const int M = 100000;
int w[N], p[N];
int dp[M + 1];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &w[i], &p[i]);
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int j;
    for (i = 0; i < n; ++i) {
        for (j = m; j >= w[i]; --j) {
            if (dp[j - w[i]] == -1) {
                continue;
            }
            dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
        }
    }
    int ans = 0;
    for (i = 0; i < m; ++i) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    
    return 0;
}