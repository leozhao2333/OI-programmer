#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N = 300100, p = 1e9 + 7;
inline int read()
{
	int x = 0,f=1; char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0'&&ch <= '9')x = x * 10 + ch - '0', ch = getchar();
	return x*f;
}
inline void write(ll x)
{
	if (x > 9)write(x / 10);
	putchar(x % 10 + '0');
}
struct data
{
	int x, y, p;
}e[N];
inline bool operator <(data a, data b) { return a.y < b.y; }
int 