#include <cstdio>
using namespace std;

typedef long long  LL;
const LL MOD = 19999997;

void matmult(LL a[2][2], LL b[2][2], LL c[2][2])
{
    int i, j, k;
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            c[i][j] = 0;
            for (k = 0; k < 2; ++k) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
}

void matpow(LL a[2][2], LL res[2][2], int n)
{
    int i, j;
    if (n == 1) {
        for (i = 0; i < 2; ++i) {
            for (j = 0; j < 2; ++j) {
                res[i][j] = a[i][j];
            }
        }
        return;
    }
    LL m1[2][2];
    matpow(a, m1, n >> 1);
    if (n & 1) {
        LL m2[2][2];
        matmult(m1, m1, m2);
        matmult(m2, a, res);
    } else {
        matmult(m1, m1, res);
    }
}

int main()
{
    int n;
    LL a[2][2], res[2][2];
    
    while (scanf("%d", &n) == 1) {
        a[0][0] = 1;
        a[0][1] = 1;
        a[1][0] = 1;
        a[1][1] = 0;
        matpow(a, res, n);
        printf("%lld\n", res[0][0]);
    }
    
    return 0;
}