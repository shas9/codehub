#include<bits/stdc++.h>

using namespace std;

const int N = 100000 + 5;

int arr[N];

int main()
{
    int initsum = 0;

    int n, k;

    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= n; i++)
    {
        int x;

        cin >> x;

        if(x == 1)
        {
            initsum += arr[i];
            arr[i] = 0;
        }
    }

    int sum = 0;

    for(int i = 1; i <= k; i++) sum += arr[i];

    int ans = sum;

    for(int i = 2; i + k - 1 <= n; i++)
    {
        sum -= arr[i - 1];
        sum += arr[i + k - 1];

        ans = max(ans, sum);
    }

    cout << initsum + ans << "\n";
}

