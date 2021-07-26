#include <bits/stdc++.h>

using namespace std;

int main()

{
    int n;
    while(scanf("%d", &n) != EOF) {
        map <char, int> :: iterator it;
        map <char, int> m;
        string s[100];
        for(int i = 1; i<= n; i++) {
            cin >> s[i - 1];
            for(int j = 0; j < 2; j++) {
                m[s[i-1][j]]++;
            }
        }

        int mark = 1;
        for(int i = 0; i < n; i++) {

            if(m[s[i][0]] <= 1 && m[s[i][1]] <= 1) {
                mark =  0;
            }
        }

        if(mark == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
