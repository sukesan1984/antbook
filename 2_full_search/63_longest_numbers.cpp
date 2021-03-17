#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

// dp[i]: 最後がaiである最長の増加列の長さ
// dp[i]
//  1 (もし、0 < j < iなるajがすべてaj > aiの時)
//  dp[j] + 1 (0 < j < iを満たすjのdp[j]の最大値 + 1)
//  dp[j]も同じように計算できる
int solve(int i, vector<int> a, int *dp)
{
	int max;

	max = 1;
	for (int j = 0; j <= i; j++)
	{
		for (int k = 0; k < j; k++)
		{
			if (a.at(k) < a.at(j))
			{
				// jまでの中のdp[k]で一番大きなやつ
				max = (max < (dp[k] + 1)) ? dp[k] + 1 : max;
			}
		}
		dp[j] = max;
	}
	return (dp[i]);
}

int main()
{
	int n;
	int ans;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a.at(i);
	}
	int *dp;
	dp = (int*) calloc(n, sizeof(int));
	dp[0] = 1;
	ans = solve(n - 1, a, dp);
	free(dp);
	printf("%d\n", ans);
	return (0);
}
