#include <iostream>

using namespace std;

// sの文字列のi番目(0 〜 n - 1)
// tの文字列のj番目(0 〜 m - 1)
// の共通部分文字列の最長の長さを得られるとする
int longest_match(int i, int j, char *s, char *t, int n, int m, int **memo)
{
	int ans;

	if (memo[i][j] > 0)
		return (memo[i][j]);
	if (i == (n - 1) && j == (m - 1))
	{
		if (s[i] == s[j])
			ans = 1;
		else
			ans = 0;
		memo[i][j] = ans;
		return (ans);
	}
	if (i == (n - 1))
	{
		if (s[i] == t[j])
			ans = (1);
		else
			ans = (longest_match(n - 1, j + 1, s, t, n, m, memo));
		memo[i][j] = ans;
		return (ans);
	}
	if (j == (m - 1))
	{
		if (s[i] == t[j])
			ans = 1;
		else
			ans = (longest_match(i + 1, m - 1, s, t, n, m, memo));
		memo[i][j] = ans;
		return (ans);
	}
	if (s[i] == t[j])
	{
		ans = (1 + longest_match(i + 1, j + 1, s, t, n, m, memo));
	}
	else
	{
		ans = max(
				longest_match(i, j + 1, s, t, n, m, memo),
				longest_match(i + 1, j, s, t, n, m, memo));
	}
	memo[i][j] = ans;
	return (ans);
}

int main()
{
	int n;
	int m;
	int **memo;
	int ans;
	cin >> n;
	cin >> m;
	char *s;
	char *t;
	s = (char*)malloc(sizeof(char) * (n + 1));
	t = (char*)malloc(sizeof(char) * (m + 1));
	scanf("%s", s);
	scanf("%s", t);
	//printf("%s\n", s);
	//printf("%s\n", t);

	memo = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		memo[i] = (int*) calloc(m, sizeof(int));
		for (int j = 0; j < m; j++)
		{
			memo[i][j] = -1;
		}
	}
	ans = longest_match(0, 0, s, t, n, m, memo);
	printf("%d\n", ans);

	free(s);
	free(t);
	return (0);
}
