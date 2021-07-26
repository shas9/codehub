#include <bits/stdc++.h>`

#define ll long long

using namespace std;


ll mat[12][12];

int main()
{
    ll i, j, n;

    // freopen("in.txt", "r", stdin);

    for(i = 1; i <= 10; i++) mat[i][1] = mat[1][i] = 1;

    for(i = 2; i <= 10; i++)
        for(j = 2; j <= 10; j++)
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1];


    while(cin >> n)
    {
        cout << mat[n][n] << endl;
    }


}

