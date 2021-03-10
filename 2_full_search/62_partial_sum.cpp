#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// i番目以降で数字Kが作れるか否かを返す
int solve(int i, int n, int K, vector<int> a, vector<int> m)
{

	if (i >= n)
		return (0);
	// i番目の数字は a.at(i)でm.at(i)個ある
	// i番目の数字をj個選んだときを考える
	printf("i: %d, K: %d\n", i, K);
	for (int j = 0; j <= m.at(i); j++)
	{
		int c = a.at(i) * j;
		if (K < c)
			continue; // この時はそのような選び方は無いのでansは変わらない
		if ((K - c) == 0) // ピッタリKに一致するなら、それ以降は何も選ばなければいいので、作れる
			return (1);
		int ans = solve(i + 1, n, K - c, a, m); // i + 1番目以降に委ねられる
		if (ans)
			return (1);
	}
	return (0);
}

int solve2(int n, int K, vector<int> a, vector<int> m, int** DP)
{
	for (int j = (n - 1); j >= 0; j--)
	{
		for (int k = 0; k <= K; k++)
		{
			if (k % a.at(j) == 0 && (k / a.at(j)) <= m.at(j))
				DP[j][k] = 1;
			else if (k > a.at(j))
				DP[j][k] = DP[j][k - a.at(j)] || DP[j + 1][k - a.at(j)];
			else
				DP[j][k] = DP[j + 1][k];
			printf("(%d, %d) = %d\n", j, k, DP[j][k]);
		}
	}
	return DP[0][K];
}

int main()
{
	int ans;
	int n;
	cin >> n;
	int K;
	cin >> K;
	vector<int> a(n);
	vector<int> m(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a.at(i);
		cin >> m.at(i);
	}
	ans = solve(0, n, K, a, m);
	printf("%d\n", ans);

	int **DP;
	DP = (int**)calloc(n + 1, sizeof(int*));
	for (int i = 0; i <= n; i++)
	{
		DP[i] = (int*)calloc(K + 1, sizeof(int));
	}
	ans = solve2(n, K, a, m, DP);
	free(DP);
	printf("%d\n", ans);
	return (0);
}
