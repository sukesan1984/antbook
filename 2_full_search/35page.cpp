#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int solve(int i, int j, vector<string> vec, int n, int m)
{
	char c;
	int r;
	int b;
	int rb;
	char rc;
	char bc;

	if ((i > n - 1) || (j > m - 1))
		return 0;
	c = vec.at(i).at(j);
	if (i == n - 1 && j == m - 1)
		return (c == 'W');
	rb = solve(i + 1, j + 1, vec, n, m);
	r = solve(i, j + 1, vec, n, m) - rb;
	b = solve(i + 1, j, vec, n, m) - rb;
	if (c != 'W')
		return (rb + r + b);
	rc = ((j + 1) > (m - 1)) ? '.' : vec.at(i).at(j + 1);
	bc = ((i + 1) > (n - 1)) ? '.' : vec.at(i + 1).at(j);

	if (rc == 'W' && bc == 'W')
		return (rb + r + b - 1);
	else if (rc != 'W' && bc != 'W')
		return (rb + r + b + 1);
	return (rb + r + b);
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	vector<string> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec.at(i);
	}

	cout << solve(0, 0, vec, n, m) << endl;
	//cout << n << endl;
	//cout << m << endl;
	//for (auto v: vec) {
	//	for (int i = 0; i < m; i++)
	//	{
	//		cout << v.at(i);
	//	}
	//	cout << endl;
	//}

	return (0);
}
