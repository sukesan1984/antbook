#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int rec(int i, int j, int n, vector<int> w, vector<int> v, int **dp)
{
	if (i == n)
		return (0);
	if (dp[i][j] > 0)
		return dp[i][j];
	if (w.at(i) > j)
	{
		dp[i][j] = rec(i + 1, j, n, w, v, dp);
		return dp[i][j];
	}
	dp[i][j] = max(rec(i + 1, j, n, w, v, dp), rec(i + 1, j - w.at(i), n, w, v, dp) + v.at(i));
	return dp[i][j];
}

int solve(int n, int W, vector<int> w, vector<int> v, int **dp)
{
	return rec(0, W, n, w, v, dp);
}

int main()
{
	int n;
	int ans;
	cin >> n;
	vector<int> w(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> w.at(i);
		cin >> v.at(i);
	}
	int W;
	cin >> W;
	int **dp;
	dp = (int**)calloc((n + 1), sizeof(int*));
	for (int i = 0; i <= n; i++)
	{
		dp[i] = (int*)calloc(W + 1, sizeof(int));
	}
	ans = solve(n, W, w, v, dp);
	for (int i = 0; i <= n; i++)
	{
		free(dp[i]);
	}
	free(dp);
	printf("%d\n", ans);
	return (0);
}
