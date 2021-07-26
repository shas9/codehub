#include <stdio.h>
long long int ztn(long long int n)
{
	if(n <= 0)
    {
        return 0;
    }
	long long int ans = 0, i;
	while(n != 0)
    {
		ans = ans + (45*(n/10));
		for(i = n/10*10+1; i <= n; i++)
			ans = ans + i%10;
		n /= 10;
	}
	return ans;
}
int main() {
	long long int p, q;
	while(1)
    {
        scanf("%lld %lld", &p, &q);
		if(p < 0 && q < 0)
        {
            break;
        }
		printf("%lld\n", ztn(q)-ztn(p-1));
	}
    return 0;
}
