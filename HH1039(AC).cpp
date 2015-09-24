#include <iostream>
#include <string>
using namespace std;

void eleminate(string s, int &sum)
{
    int score;
    int n, i, j;
    string s1;
    
    do {
        score = 0;
        n = s.length();
        s1 = "";
        i = 0;
        while (i < n) {
            if (i >= n - 1 || s[i] != s[i + 1]) {
                s1.push_back(s[i++]);
            } else {
                j = i + 1;
                while (j < n && s[i] == s[j]) {
                    ++j;
                }
                score += j - i;
                i = j;
            }
        }
        s = s1;
        sum += score;
    } while (score > 0);
}

int main()
{
    ios::sync_with_stdio(false);
    
    string s, s1;
    int n;
    int cases, ci;
    int sum, msum;
    int i, j;
    
    cin >> cases;
    for (ci = 0; ci < cases; ++ci) {
        cin >> s;
        n = s.length();
        msum = 0;
        for (i = 0; i <= n; ++i) {
            s1 = s.substr(0, i) + 'A' + s.substr(i, n - i);
            for (j = 0; j < 3; ++j) {
                s1[i] = 'A' + j;
                sum = 0;
                eleminate(s1, sum);
                msum = max(msum, sum);
            }
        }
        cout << msum << endl;
    }
    
    return 0;
}