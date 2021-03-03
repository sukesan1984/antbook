#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

// i番目以降で重さj以下となる最大の価値
int rec(int i, int j, int n, vector<int> w, vector<int> v)
{
	int res;

	if (i == n)
		return (0);
	if (j < w.at(i))
		return rec(i + 1, j, n, w, v);
	res = max(rec(i + 1, j, n, w, v), rec(i + 1, j - w.at(i), n, w, v) + v.at(i));
	return (res);
}

int solve(int n, int W, vector<int> w, vector<int> v)
{
	return rec(0, W, n, w, v);
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

	ans = solve(n, W, w, v);
	printf("%d\n", ans);
}
