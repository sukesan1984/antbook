#include <cstdio>
#include <iostream>

using namespace std;

// 時刻tで受けられる最大の仕事を返す
int solve(int t, int *S, int *T, int N)
{
	int max = 0;
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		// 今の時刻よりも未来にある仕事は受けられる
		if (S[i] > t)
		{
			// この仕事を引き受けると、その仕事の終了時刻から先の最大の仕事量 + 1
			tmp = solve(T[i], S, T, N) + 1;
			max = (tmp > max) ? tmp : max;
		}
	}
	return (max);
}

int main()
{
	int N;
	int ans;

	cin >> N;
	int S[N];
	int T[N];
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
		cin >> T[i];
	}
	ans = solve(0, S, T, N);
	printf("%d\n", ans);
}
