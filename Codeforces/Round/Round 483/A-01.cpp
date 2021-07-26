#include <bits/stdc++.h>`

using namespace std;

int main()
{
    long long int a, b, n, ans;

    vector < long long int > vec;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(),vec.end());

    if(n % 2 == 1)
    {
        ans = vec[(n / 2)];
    }
    else
    {
        ans = vec[n / 2];
    }

    cout << ans << endl;



}


