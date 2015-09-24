#include <cstdio>
#include <cstring>
using namespace std;

const int PL = 10000;
const int SL = 1000000;
char s[SL + 5];
char p[PL + 5];
int ls, lp;
int nx[PL + 5];

void calcNext()
{
    memset(nx, 0, sizeof(nx));
    int i = 0;
    int j = -1;
    nx[i] = j;
    while (i <= lp) {
        if (j == -1 || p[i] == p[j]) {
            nx[++i] = ++j;
        } else {
            j = nx[j];
        }
    }
}

int KMPMatch()
{
    int i = 0;
    int j = 0;
    int ans = 0;
    while (i <= ls) {
        if (j == lp) {
            j = nx[j];
            ++ans;
        } else if (j == -1 || s[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = nx[j];
        }
    }
    return ans;
}

int main()
{
    int cn, ci;
    scanf("%d", &cn);
    for (ci = 0; ci < cn; ++ci) {
        scanf("%s%s", p, s);
        ls = strlen(s);
        lp = strlen(p);
        calcNext();
        printf("%d\n", KMPMatch());
    }
    
    return 0;
}