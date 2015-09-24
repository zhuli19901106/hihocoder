#include <cstring>
#include <iostream>
#include <set>
using namespace std;

set<int> fib;

int main()
{
    fib.insert(1);
    fib.insert(2);
    fib.insert(3);
    fib.insert(5);
    fib.insert(8);
    fib.insert(13);
    fib.insert(21);
    
    int b[26];
    int cc;
    string s;
    string sub;
    
    ios::sync_with_stdio(false);
    cin >> s;
    int n = s.length();
    
    set<string> ans;
    int i, j;
    for (i = 0; i < n; ++i) {
        sub.clear();
        memset(b, 0, sizeof(b));
        cc = 0;
        for (j = i; j < n; ++j) {
            sub.push_back(s[j]);
            if (!b[s[j] - 'a']) {
                b[s[j] - 'a'] = 1;
                ++cc;
            }
            if (fib.find(cc) != fib.end()) {
                ans.insert(sub);
            }
        }
    }
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}