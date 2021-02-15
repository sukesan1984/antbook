#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int f(int i, vector<int> vec, int n, int k)
{
	int c;

	if (i >= n)
		return false;

	c = vec.at(i);
	if ((k - c) == 0)
		return true;
	// iを含まないものと含むもので再帰的に見る
	return (f(i + 1, vec, n, k) || f(i + 1, vec, n, k - c));
}

int solve(int n, vector<int> vec, int k)
{
	return f(0, vec, n, k);
}

// input:
// n
// a1, a2, .... an
// k
int main()
{
	int n;
	int k;
	cin >> n;

	vector<int> vec(n);
	for (int i =0; i < n; i++) {
		cin >> vec.at(i);
	}
	cin >> k;
	if (solve(n, vec, k))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
