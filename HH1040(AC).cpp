#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long LL;
const LL N = 100000;

bool solve()
{
    unordered_set<LL> us;
    vector<LL> v1, v2;
    LL x1, x2, y1, y2;
    int i, j;
    for (i = 0; i < 4; ++i) {
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        us.insert(x1 * N + y1);
        us.insert(x2 * N + y2);
        v1.push_back((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    if (us.size() != 4) {
        return false;
    }
    sort(v1.begin(), v1.end());
    if (v1[0] <= 0 || v1[0] != v1[1] || v1[2] != v1[3]) {
        return false;
    }
    unordered_set<LL>::iterator it1, it2;
    for (it1 = us.begin(); it1 != us.end(); ++it1) {
        for (it2 = it1, ++it2; it2 != us.end(); ++it2) {
            x1 = *it1 / N;
            y1 = *it1 % N;
            x2 = *it2 / N;
            y2 = *it2 % N;
            v2.push_back((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
    }
    sort(v2.begin(), v2.end());
    for (i = 0; i < 4; ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    if (v2[4] != v2[5] || v2[4] != v2[0] + v2[2]) {
        return false;
    }
    return true;
}

int main()
{
    int cn, ci;
    
    scanf("%d", &cn);
    for (ci = 0; ci < cn; ++ci) {
        printf(solve() ? "YES\n" : "NO\n");
    }
    
    return 0;
}