#include <bits/stdc++.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long value[21][21][21], RowSum[21][21][21];
void sol(int A, int B, int C) {
    long long mx = value[0][0][0];
    int i, j, k, p, q;

    for(i = 0; i < A; i++)
        for(j = 0; j < B; j++)
            for(k = 0; k < C; k++)
                mx = max(mx, value[i][j][k]);

    for(p = 0; p < A; p++)
    for(q = p; q < A; q++)
    {
        for(i = 0; i < B; i++)
        {
            long long sum[21] = {}, tmp;
            for(j = i; j < B; j++)
            {
                tmp = 0;
                for(k = 0; k < C; k++)
                {
                    printf("p = %d, q = %d, i = %d, j = %d, k = %d\n", p , q, i, j, k);
                    sum[k] += RowSum[q][j][k];

                    cout << "Sum += :" << sum[k] << endl;
                    if(p)
                    {
                        sum[k] -= RowSum[p-1][j][k];
                        cout << "Sum -= :" << sum[k] << endl;
                    }
                    tmp += sum[k];
                    mx = max(mx, tmp);

                    cout << "Temp: " << tmp << " Max: " << mx << endl;
                    if(tmp < 0)
                    {
                         cout << "TEMP = 0" << endl;
                         tmp = 0;
                    }
                }
            }
        }
    }
    printf("%lld\n", mx);
}
int main() {
    int testcase, A, B, C;
    int i, j, k;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d %d", &A, &B, &C);
        memset(RowSum, 0, sizeof(RowSum));
        for(i = 0; i < A; i++) {
            for(j = 0; j < B; j++) {
                for(k = 0; k < C; k++) {
                    scanf("%lld", &value[i][j][k]);
                    RowSum[i][j][k] = value[i][j][k];
                    if(i)
                    {
                        RowSum[i][j][k] += RowSum[i-1][j][k];
                    }

                    cout << i << " " << j << " " << k << endl;

                    cout << "value[i][j][k]: " << value[i][j][k] << endl;
                    cout << "RowSum[i][j][k]: " << RowSum[i][j][k] << endl;
                }
            }
        }
        sol(A, B, C);
        if(testcase)
            puts("");
    }
    return 0;
}
/*
1
2 3 3
21 -39 4 -39 4 -44 1 -32 -25 -35 2 17 6 10 2 -12 -22 35
*/
