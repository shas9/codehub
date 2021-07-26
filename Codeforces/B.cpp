#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, k;

    vector < long long int > x;

    long long int i, j = 0;

    cin >> n >> k;

    for(i = 1; i * i <= n; i++)
    {
        //cout << i << endl;
        if(n % i != 0) continue;

        j++;

        if(k == j)
        {
            cout << i << endl;
            return 0;
        }

        if(i * i == n) continue;

        x.push_back(n / i);
    }

    //cout << x.size() << endl;

    sort(x.begin(),x.end());

    if(k - j > x.size())
    {
        cout << -1 << endl;
        return 0;
    }

    cout << x[k - j - 1] << endl;
}
