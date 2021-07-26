#include <bits/stdc++.h>`

using namespace std;

int main()
{
    int n;
    double input, keltu, ans;

    cin >> n;

    ans = 0;

    for(int cs = 1; cs <= n; cs++)
    {
        cin >> input;

        ans += input;
    }

    cin >> keltu;

    ans /= n;

    ans = abs(ans - keltu);

    cout << ans << endl;


}


