#include<bits/stdc++.h>

using namespace std;

vector < int > coordinate;

int main()
{
    int n, p;

    cin >> n >> p;

    coordinate.assign(p + 1,0);

    for(int i = 1; i <= n; i++)
    {
        int x, r;

        cin >> x >> r;

        int left = (x - r);
        int right = (x + r);

        if(left < 0) left = 0;
        if(right > p) right = p;

        /// Adding the counter

        // for(int j = left; j <= right; j++) coordinate[j]++;

        coordinate[left] += 1;
        coordinate[right + 1] -= 1;

        /// End
    }

    for(int i = 1; i <= p; i++) coordinate[i] += coordinate[i - 1];

    for(int i = 0; i <= p; i++)
    {
        if(coordinate[i] > 1) coordinate[i] = 0;
    }

    int ans = 0;
    int z = 0;

    for(int i = 0; i <= p; i++)
    {
        if(coordinate[i] == 1) z = 0;
        else z++;

        ans = max(ans, z);
    }

    cout << ans << "\n";
}

