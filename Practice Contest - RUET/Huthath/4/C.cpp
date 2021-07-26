#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")




using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    string input;
    string temp = "";

    map < string, string > store;

    store[".-"] = "A";
    store["-..."] = "B";
    store["-.-."] = "C";
    store["-.."] = "D";
    store["."] = "E";
    store["..-."] = "F";
    store["--."] = "G";
    store["...."] = "H";
    store[".."] = "I";
    store[".---"] = "J";
    store["-.-"] = "K";
    store[".-.."] = "L";
    store["--"] = "M";
    store["-."] = "N";
    store["---"] = "O";
    store[".--."] = "P";
    store["--.-"] = "Q";
    store[".-."] = "R";
    store["..."] = "S";
    store["-"] = "T";
    store["..-"] = "U";
    store["...-"] = "V";
    store[".--"] = "W";
    store["-..-"] = "X";
    store["-.--"] = "Y";
    store["--.."] = "Z";

    while(cin >> input)
    {
        i = 0;
        while(1)
        {
            temp = "";
            while(1)
            {
                if(input[i] == '/' || input[i] == '\0')
                {
                    i++;
                    break;
                }
                temp += input[i];
                i++;
            }



            //cout << i << endl;

            //cout << temp;

            cout << store[temp];
            if((input[i] == '/'))
            {
                cout << " ";
                i++;
            }

            if(i > (input.length() - 1))
            {
                break;
            }
        }

        printf("\n");
    }


}

