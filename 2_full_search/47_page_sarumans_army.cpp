#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int R;
	int ans;
	int last_unmarked;
	int candidate;

	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec.at(i);
	}
	cin >> R;
	sort(vec.begin(), vec.end());
	ans = 0;
	last_unmarked = 0;
	candidate = 0;
	for (int i = 0; i < N; i++)
	{
		if (vec.at(i) <= vec.at(last_unmarked) + R)
		{
			candidate = i;
			continue;
		}
		// 最初にここに来たときにcandidateにマークをしつつ、今のindexをlast_unmarkedにする
		ans++;
		last_unmarked = i;
	}
	if (candidate == (N - 1))
		ans++;

	printf("%d\n", ans);

	return (0);
}
