#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char UNDEF1 = -2;
const char UNDEF2 = -3;

void interleave(string &s, string &t)
{
    int n = s.length();
    t.clear();
    int i;
    for (i = 0; i < n; ++i) {
        t.push_back(UNDEF1);
        t.push_back(s[i]);
    }
    t.push_back(UNDEF2);
}

int Manacher(string &s)
{
    string t;
    interleave(s, t);
    vector<int> r(t.length(), 1);
    int i, maxi, maxr;
    int n = t.length();
    
    maxi = 0;
    maxr = 0;
    r.resize(n);
    r[0] = 0;
    for (i = 1; i < n; ++i) {
        r[i] = 1;
        if (i < maxr) {
            r[i] = r[2 * maxi - i];
            if (i + r[i] > maxr) {
                r[i] = maxr - i;
            }
        }
        while (t[i - r[i]] == t[i + r[i]]) {
            ++r[i];
        }
        if (i + r[i] > maxr) {
            maxi = i;
            maxr = i + r[i];
        }
    }
    
    maxr = 0;
    for (i = 0; i < n; ++i) {
        if (i & 1) {
            maxr = max(maxr, (r[i] - 1 >> 1 << 1) + 1);
        } else {
            maxr = max(maxr, r[i] >> 1 << 1);
        }
    }
    return maxr;
}

int main()
{
    ios::sync_with_stdio(false);
    
    int cn, ci;
    string s;
    cin >> cn;
    for (ci = 0; ci < cn; ++ci) {
        cin >> s;
        cout << Manacher(s) << endl;
    }
    
    return 0;
}