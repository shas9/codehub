// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int

    srand(time(NULL));


    int n = rand(1, 9);
    int m = rand(3, min((1 << n) - 1, 20));
    printf("%d %d\n", n, m);
    vector < int > v;

//    cout << (1 << n) << "\n";

    for(int i = 1; i < (1 << n); i++) v.push_back(i);

    random_shuffle(v.begin(),v.end());

//    cout << v.size() << " " << m << "\n";

    for(int i = 0; i < m; ++i) {

        int x = v[i];
        for(int j = 0; j < n; j++)
        {
            if((x & (1 << j))) printf("1");
            else printf("0");
        }

        printf("\n");
    }
    puts("");
}

