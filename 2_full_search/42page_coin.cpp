#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int ans;
	int A;
	int C1, C5, C10, C50, C100, C500;

	cin >> A;
	cin >> C1;
	cin >> C5;
	cin >> C10;
	cin >> C50;
	cin >> C100;
	cin >> C500;
	ans = 0;
	while ((A - 500) > 0 && C500 > 0)
	{
		ans++;
		A = A - 500;
		C500--;
	}
	while ((A - 100) >= 0 && C100 > 0)
	{
		ans++;
		A = A - 100;
		C100--;
	}
	while ((A - 50) >= 0 && C50 > 0)
	{
		ans++;
		A = A - 50;
		C50--;
	}
	while ((A - 10) >= 0 && C10 > 0)
	{
		ans++;
		A = A - 10;
		C10--;
	}
	while ((A - 5) >= 0 && C5 > 0)
	{
		ans++;
		A = A - 5;
		C5--;
	}

	while ((A - 1) >= 0 && C1 > 0)
	{
		ans++;
		A = A - 1;
		C1--;
	}

	printf("%d\n", ans);
	return (0);
}
