#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define ll long long
using namespace std;
inline ll max(ll a, ll b) { return a>b ? a : b; }
inline ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9')x = x * 10 + ch - '0', ch = getchar();
	return x*f;
}
inline void write(ll x)
{
	if (x == 0) { puts("0"); return; }
	if (x<0)putchar('-'), x = -x;
	int a[30], i = 1;
	while (x>0)
	{
		a[i] = x % 10;
		x = x / 10;
		i++;
	}
	i--;
	for (; i >= 1; i--)
		putchar('0' + a[i]);
	puts("");
}
long long a[100][100], f[100][100];
long long n, m;
long long sum;
int main()
{
	n = read(); m = read();
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			a[i][j] = read();
		}
	}
	for (ll I = 1; I <= n; I++)
	{
		memset(f, 0, sizeof(f));
		for (ll i = 1; i <= m; i++)
		{
			for (ll j = m; j >= 1; j--)
			{
				if (j >= i)
				{
					if (i - 1 >= 1)f[i][j] = max(f[i][j], f[i - 1][j] + 1ll * a[I][i - 1] * pow(2, m - j + i - 1));
					if (j + 1 <= m)f[i][j] = max(f[i][j], f[i][j + 1] + 1ll * a[I][j + 1] * pow(2, m - j + i - 1));
				}
				else break;
			}
		}
		long long temp = 0;
		for (ll i = 1; i <= m; i++)
			temp = max(temp, f[i][i] + 1ll * pow(2, m)*a[I][i]);
		sum += temp;
	}
	write(sum);
}