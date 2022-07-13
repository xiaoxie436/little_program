#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
int a[maxn], dp[maxn], s[maxn], n = 0, k, ans;
void dfs()
{
	for (int i = 1; i <= n; ++i)
	{
	}
}
int main()
{
	ios::sync_with_stdio(0);
	while (cin >> k)
		a[++n] = k;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1;
		int l = 0, r = ans + 1;
		while (r - l > 1)
		{
			int mid = (l + r) >> 1;
			//在右侧
			if (s[mid] >= a[i])
			{
				l = mid;
			}
			//在左侧
			else
			{
				r = mid;
			}
		}
		dp[i] = l + 1;
		s[dp[i]] = a[i];
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	ans = 0;
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1;
		int l = 0, r = ans + 1;
		while (r - l > 1)
		{
			int mid = (l + r) >> 1;
			if (s[mid] < a[i])

			{
				l = mid;
				mid++;
				i--;
			}
			else
			{
				r = mid;
				mid--;
				i++;
			}
		}
		dp[i] = l + 1;
		s[dp[i]] = a[i];
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}