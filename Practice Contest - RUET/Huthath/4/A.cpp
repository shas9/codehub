#include <bits/stdc++.h>

using namespace std;

int main()

{
    int n;
    while(scanf("%d", &n) != EOF) {

        int ans = 0;
        map <string, int> m;
        for(int i = 1; i <= n; i++) {
            char a[100];
            scanf("%s", a);

            map <char, bool> mp;
            string s = "";

            int ln = strlen(a);
            for(int j = 0; j < ln;j++) {
                if(mp[a[j]] == 0) {
                    mp[a[j]] = 1;
                    s += a[j];
                }
            }

            sort(s.begin(), s.end());

            if(m[s] == 0) {
                m[s] = 1;
                ans++;
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}
