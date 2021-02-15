#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

typedef struct	s_point
{
	int x;
	int y;
	int turn;
}				t_point;

void push(vector<string> maze, int **memo, queue<t_point> *q, int i, int j, int n, int m, int turn)
{
	t_point p;

	if (i < 0 || i >= n || j < 0 || j >= m)
		return;
	if (maze.at(i).at(j) == '#')
		return;
	if (memo[i][j] != 0)
		return;
	p.x = i;
	p.y = j;
	p.turn = turn;
	q->push(p);
}

void walk(vector<string> maze, int i, int j, int n, int m, int **memo, int turn, queue<t_point> *q)
{
	t_point next;
	printf("walk: %d, %d\n", i, j);

	if (i < 0 || i >= n || j < 0 || j >= m)
		return;
	if (memo[i][j] != 0)
		return;
	if (maze.at(i).at(j) == '#')
		memo[i][j] = -1;
	push(maze, memo, q, i - 1, j, n, m, turn + 1);
	push(maze, memo, q, i, j - 1, n, m, turn + 1);
	push(maze, memo, q, i + 1, j, n, m, turn + 1);
	push(maze, memo, q, i, j + 1, n, m, turn + 1);
	memo[i][j] = turn;
	while(!q->empty())
	{
		next = q->front();
		q->pop();
		walk(maze, next.x, next.y, n, m, memo, next.turn, q);
	}
}

// 壁: #
// 通路: .
int main()
{
	int n, m;
	int s_x, s_y;
	int g_x, g_y;
	int **memo;
	queue<t_point> q;

	cin >> n;
	cin >> m;
	vector<string> vec(n);
	s_x = 0;
	s_y = 0;
	g_x = 0;
	g_y = 0;
	for (int i = 0; i < n; i++)
		cin >> vec.at(i);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(vec.at(i).at(j) == 'S')
			{
				s_x = i;
				s_y = j;
			}
			else if (vec.at(i).at(j) == 'G')
			{
				g_x = i;
				g_y = j;
			}
		}
	}
	printf("S: (%d, %d), G: (%d, %d)\n", s_x, s_y, g_x, g_y);
	memo = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		memo[i] = (int*)calloc(m, sizeof(int));
	walk(vec, s_x, s_y, n, m, memo, 0, &q);
	printf("walk end\n");
	printf("%d\n", memo[g_x][g_y]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("|%2.0d|", memo[i][j]);
		printf("\n");
	}
	return (0);
}
