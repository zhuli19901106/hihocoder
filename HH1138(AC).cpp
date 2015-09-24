// Dijkstra's algorithm with heap optimization.
// Didn't expect the first experience to be so hard.
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long int LL;
const int N = 100000;
LL x[N], y[N];
LL d[N];
vector<unordered_set<int> > e;
int n;

typedef struct Point {
    int i;
    LL x, y;
} Point;
vector<Point> p;

bool compX(const Point &p1, const Point &p2)
{
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    }
    if (p1.y != p2.y) {
        return p1.y < p2.y;
    }
    return false;
}

bool compY(const Point &p1, const Point &p2)
{
    if (p1.y != p2.y) {
        return p1.y < p2.y;
    }
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    }
    return false;
}

LL dist(int i, int j)
{
    return min(abs(x[i] - x[j]), abs(y[i] - y[j]));
}

void dijkstra(int start, int end)
{
    int i;
    for (i = 0; i < n; ++i) {
        d[i] = -1;
    }
    
    priority_queue<pair<LL, int> > pq;
    pq.push(make_pair(0, start));
    
    LL dd;
    int ii;
    while (!pq.empty()) {
        dd = pq.top().first;
        ii = pq.top().second;
        pq.pop();
        /*
            Do you know why it's negative here?
            Because the default priority_queue is a max heap.
            Negating make it functionally a min heap.
        */
        d[ii] = -dd;
        if (ii == end) {
            return;
        }
        for (auto it = e[ii].begin(); it != e[ii].end(); ++it) {
            if (d[*it] == -1) {
                pq.push(make_pair(dd - dist(ii, *it), *it));
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    int i;
    
    p.resize(n);
    for (i = 0; i < n; ++i) {
        scanf("%lld%lld", &x[i], &y[i]);
        p[i].i = i;
        p[i].x = x[i];
        p[i].y = y[i];
    }
    e.resize(n);
    
    sort(p.begin(), p.end(), compX);
    for (i = 1; i < n; ++i) {
        e[p[i - 1].i].insert(p[i].i);
        e[p[i].i].insert(p[i - 1].i);
    }
    
    sort(p.begin(), p.end(), compY);
    for (i = 1; i < n; ++i) {
        e[p[i - 1].i].insert(p[i].i);
        e[p[i].i].insert(p[i - 1].i);
    }
    
    dijkstra(0, n - 1);
    printf("%lld\n", d[n - 1]);
    
    return 0;
}