#include <bits/stdc++.h>

using namespace std;

char s[40], cmb[40], used[40];
int len, n, cnt = 0;

void comb(int indx, int indx2)

{
    if(indx2 == n) {
        cmb[indx2] = '\0';
        printf("%s", cmb);
        printf("\n");
        return;
    }

    for(int j = indx; j < len; j++) {
        if(indx2 > 0 && cmb[indx2 - 1] > s[j])
            continue;

        if(used[j] == '\0') {
            cmb[indx2] = s[j];
            used[j] = '1';
            comb(j + 1, indx2 + 1);
            used[j] = '\0';

            while(s[j] == s[j + 1] && j + 1 < len) j++;
        }

    }
}

int main()

{
    while(scanf("%s %d", s, &n) != EOF) {
       memset(used, '\0', sizeof(used));
       len = strlen(s);
       sort(s, s + len);
       comb(0, 0);
    }


    return 0;
}
