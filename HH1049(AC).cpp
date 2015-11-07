#include <cstdio>
#include <cstring>
using namespace std;

const int N = 26;
char pre[N + 1], in[N + 1];
int inpos[N];
int tr[N][2];
int root;
int n;

int recover(int p1, int p2, int i1, int i2)
{
    if (p1 > p2 || i1 > i2) {
        return -1;
    }
    int r = pre[p1] - 'A';
    int rp = inpos[r];
    tr[r][0] = recover(p1 + 1, p1 + rp - i1, i1, rp - 1);
    tr[r][1] = recover(p1 + 1 + rp - i1, p2, rp + 1, i2);

    return r;
}

void postorder(int r)
{
    if (r == -1) {
        return;
    }
    postorder(tr[r][0]);
    postorder(tr[r][1]);
    putchar(r + 'A');
}

int main()
{
    scanf("%s%s", pre, in);
    root = pre[0] - 'A';
    n = strlen(pre);

    int i;
    for (i = 0; i < n; ++i) {
        inpos[in[i] - 'A'] = i;
    }
    recover(0, n - 1, 0, n - 1);
    postorder(root);
    putchar('\n');
    
    return 0;
}