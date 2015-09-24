#include <cstdio>
using namespace std;

const int N = 205;
const int d[8][2] = {
    {-1, -1},
    {-1,  0},
    {-1, +1},
    { 0, +1},
    {+1, +1},
    {+1,  0},
    {+1, -1},
    { 0, -1}
};
char a[N][N];
char b[3][4];
int n, m;

bool checkOK(int x, int y)
{
    int i, j;
    int x1, y1;
    if (a[x][y] != b[1][1]) {
        return false;
    }
    for (i = 0; i < 8; i += 2) {
        for (j = 0; j < 8; ++j) {
            x1 = x + d[(j + i) % 8][0];
            y1 = y + d[(j + i) % 8][1];
            if (a[x1][y1] != b[1 + d[j][0]][1 + d[j][1]]) {
                break;
            }
        }
        if (j == 8) {
            return true;
        }
    }
    return false;
}

int main()
{
    int i, j;
    
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (i = 0; i < 3; ++i) {
        scanf("%s", b[i]);
    }
    for (i = 1; i < n - 1; ++i) {
        for (j = 1; j < m - 1; ++j) {
            if (checkOK(i, j)) {
                printf("%d %d\n", i + 1, j + 1);
            }
        }
    }
    
    return 0;
}