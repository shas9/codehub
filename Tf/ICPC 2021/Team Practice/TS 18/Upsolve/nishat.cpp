#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int ans = 0;
    int same = 0;
    int diff = 0;
    int last = -1;
    int input;

    for(int i = 1; i <= n; i++)
    {
        cin >> input;

        if(input != last)
        {
            diff = same;
            same = 0;
        }

        same++;

        last = input;

        ans = max(ans, min(diff, same) * 2);
    }

    cout << ans << "\n";
}
