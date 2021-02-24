#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, vector<int> vec, int index, int remain)
{
	if (index >= (n - 1))
		return (0);
//	printf("index: %d, remain: %d\n", index, remain);
	return vec.at(index) + remain + solve(n, vec, index + 1, remain - vec.at(index));
}

int main()
{
	int N;
	int sum;
	cin >> N;
	vector<int> vec(N);
	int ans;

	sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> vec.at(i);
		sum += vec.at(i);
	}
	sort(vec.begin(), vec.end(), [](int a, int b) {
		return a > b;
	});
	ans = solve(N, vec, 0, sum - vec.at(0));
	printf("%d\n", ans);

	return (0);
}
