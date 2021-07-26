#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define ll int

char str[M];
vector<int> vec[M];
bool valid[M];
int nxt[M], ans[M];

int main()
{
    int n;
    scanf("%d%s", &n, str+1);

    int zlst = n+1, olst = n+1;
    for(int i = n; i; i--)
    {
        if(str[i] == '0') zlst = i;
        else if(str[i] == '1') olst = i;

        int x = max(zlst, olst)-i;
        vec[x].push_back(i);
    }

    for(ll i = 1; i <= n; i++)
    {
		cout << i << ": ";

		for(auto it: vec[i]) cout << it << " ";

		cout << endl;
    }

    for(int i = n; i; i--)
    {
		cout << i << endl;
        for(int x: vec[i])
        {
            for(int j = x; j && !valid[j]; j--) nxt[j] = x;
            valid[x] = true;
        }

        cout << "Valid: ";
        for(ll j = 1; j <= n; j++) cout << valid[j] << " ";
        cout << endl;

        cout << "NXT: ";
        for(ll j = 1; j <= n; j++) cout << nxt[j] << " ";
        cout << endl;

        int j = 1;

        cout << "Start: ";
        while(j <= n)
        {
            int pore = nxt[j];
            if(!pore) break;

            cout << pore << " -> ";

            ans[i]++;
            j = pore+i;
        }

        cout << endl;
    }

    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}
