#include <stdio.h>

using namespace std;

int main()
	{
		int t;
		int n;
		scanf("%d", &t);

		for(int i = 0; i < t; i++)
			{
				scanf("%d", &n);
				if(n % 2 == 0)
					printf("%d\n", n / 2);
				else
					printf("%d\n", (n / 2) + 1);
			}
		return 0;
	}
