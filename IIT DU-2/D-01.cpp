#include <bits/stdc++.h>

using namespace std;

int main()
{
	string input = " AUJGDTU ROLKILSNJKOL QEATGJIL PIDTDPZ XCVBXNSVMC ";

	set < string > store;

	int i, j, k, l;

	string a;

	//cout << input.size() << endl;
	i = 1;
	k = 0;

	while(i < input.size())
    {
        store.clear();
        if(k)
        {
            cout << " ";
        }
        k = 1;
        while(1)
        {
            a = input[i];
            if(input[i] == ' ')
            {
                l = store.size();
                cout << l;
                i++;
                break;
            }
            store.insert( a );
            i++;
        }
    }
	cout << endl;

	return 0;
}
