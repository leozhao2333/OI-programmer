#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define ll long long
ll n,k,t;
inline ll Sqrt(ll n)
{
	ll x = sqrt(n);
	if (x*x == n)return x;
	if (x*x>n)
	{
		while (x*x>n)x--;
		return x;
	}
	else
	{
		while ((x + 1)*(x + 1)<n)x++;
		return x;
	}
}
int main()
{
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &k);
		if (n == 0) { puts("0"); continue; }
		ll x = Sqrt(n);
		if (k == 1)
		{
			if (n == 1) { printf("1\n"); continue; }
			if (x*x == n)printf("%lld\n", x * 2 - 1);
			else printf("%lld\n", x * 2);
		}
		else
		{
			if (n == 1 || n == 3)printf("-1\n");
			else if (n == 2)printf("1\n");
			else if (n == 5)printf("3\n");
			else
			{
				ll temp = Sqrt(n - 1);
				if (x*x == n || temp*temp == n - 1)printf("%lld\n", x * 2 - 2);
				else printf("%lld\n", x * 2 - 1);
			}
		}
	}
}