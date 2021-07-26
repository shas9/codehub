#include <bits/stdc++.h>`
using namespace std;

int main()
{

    long long int x;
    bool on = 1;

    string s;

    cin >> x >> s;
    int i;

    if(x > 2)
    {
        for(i = 1; i < x; i++)
        {
            if(s[i] == s[i - 1] && s[i] == '1') on = 0;
        }
        for(i = 1; i < x - 1; i++)
        {
            if(s[i - 1] == s[i + 1] && s[i - 1] == '0') on = 0;
        }
    }

    if(x == 2)
    {
        if(s[0] == s[1]) on = 0;
    }
    if(x == 1)
        if(s[0] == '0') on = 0;

    if(on) cout << "Yes" << endl;
    else cout << "No" << endl;





}


