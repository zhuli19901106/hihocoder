#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100;
int a[N][N];
int n;

int main()
{
    int i, j;
    
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j <= i; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i < n; ++i) {
        a[i][0] += a[i - 1][0];
        for (j = 1; j < i; ++j) {
            a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
        }
        a[i][i] += a[i - 1][i - 1];
    }
    int ans = 0;
    for (i = 0; i < n; ++i) {
        ans = max(ans, a[n - 1][i]);
    }
    printf("%d\n", ans);
    
    return 0;
}