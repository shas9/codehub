#include <bits/stdc++.h>
int N, M, L = -1000000000, R = 1000000000;

using namespace std;
int main()
{
	scanf("%d%d", &N, &M);
	while (M--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		L = std::max(L, (x + y - 1) / y);
		cout << "L is: "<<  x + y - 1 << " " << y << " " << (x + y - 1) / y << endl;
		if (y > 1)
        {
			R = std::min(R, (x - 1) / (y - 1));
			cout << "R is: " << x-1 << " " << y-1 << " " << (x - 1) / (y - 1) << endl;
	}}

	cout << L << " " << R << endl;
	if ((N + L - 1) / L == (N + R - 1) / R)
    {
		printf("%d\n", (N + L - 1) / L);
    }
	else
		puts("-1");
	return 0;
}
