#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int W, vector<int> w, vector<int> v, int **DP)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			int tmp_v = -1;
			for (int k = 0; (k * w[i]) <= j; k++)
			{
				tmp_v = max(tmp_v, DP[i-1][j - (k * w[i])] + v[i] * k);
			}
			DP[i][j] = tmp_v;
		}
	}
	return (DP[n][W]);
}

int main()
{
	int ans;
	int n;
	cin >> n;
	int W;
	cin >> W;
	vector<int> w(n+1);
	vector<int> v(n+1);
	int **DP;
	DP = (int**)calloc((n + 1), sizeof(int*));
	for (int i = 0; i <= n; i++)
		DP[i] = (int*)calloc(W + 1, sizeof(int));

	for (int i = 1; i <= n; i++)
	{
		cin >> w.at(i);
		cin >> v.at(i);
	}
	ans = solve(n, W, w, v, DP);
	for (int i = 0; i <= n; i++)
		free(DP[i]);
	free(DP);
	printf("%d\n", ans);
}
