#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

int get_min(char *S, int head, int tail)
{
	if (head == tail)
		return head;
	return (S[head] < S[tail]) ? head : tail;
}

int main()
{
	int N;
	cin >> N;
	int head;
	int tail;
	int tmp;
	char *S;
	char *T;

	S = (char*)calloc(N, sizeof(char));
	T = (char*)calloc(N, sizeof(char));

	cin >>  S;
	head = 0;
	tail = N - 1;
	for (int i = 0; i < N; i++)
	{
		tmp = get_min(S, head, tail);
		T[i] = S[tmp];
		if (tmp == head)
			head += 1;
		else
			tail -= 1;
	}
	printf("%s\n", T);
	free(S);
	free(T);
	return (0);
}
