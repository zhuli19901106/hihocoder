// O(n)
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100;

int main()
{
    int n, m;
    int a[N];
    int s[N + 1];
    int i, j, x;
    int cn, ci;
    int ans;
    
    scanf("%d", &cn);
    for (ci = 0; ci < cn; ++ci) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; ++i) {
            scanf("%d", &x);
            a[--x] = 1;
        }
        s[0] = 0;
        for (i = 0; i < N; ++i) {
            s[i + 1] = s[i] + a[i];
        }
        i = j = 0;
        ans = 0;
        while (i < N) {
            if (s[j] - s[i] <= m) {
                ans = max(ans, j - i);
                if (j < N) {
                    ++j;
                    continue;
                } else {
                    break;
                }
            }
            
            ++i;
            while (s[j] - s[i] > m) {
                ++i;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}