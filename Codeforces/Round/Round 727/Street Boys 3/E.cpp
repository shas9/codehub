#include <bits/stdc++.h>

using namespace std;

/*
 computer != COMputer -> computer

*/

int main()
{
    string s1, s2;

    cin >> s1;

    int ans = 0;

    while(cin >> s2)
    {
        if(s2 == "END_OF_TEXT") break;

        for(int i = 0; i < s2.size(); i++) s2[i] = tolower(s2[i]);
        if(s1 == s2) ans++;
    }

    cout << ans << "\n";


}

