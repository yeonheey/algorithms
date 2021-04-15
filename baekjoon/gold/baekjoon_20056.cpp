#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

struct Fireball {
	int r, c;
	int measure, speed, dir;
	Fireball(int _r, int _c, int _measure, int _speed, int _dir)
		: r(_r), c(_c), measure(_measure), speed(_speed), dir(_dir)
	{}
};

int N, M, K;
queue<Fireball> board[51][51];
int dir_r[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dir_c[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void moveAllFireball()
{
	queue<Fireball> moveBall;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].size() == 0) continue;
			
			while (!board[i][j].empty())
			{
				Fireball temp = board[i][j].front();
				board[i][j].pop();
				
				temp.c = (temp.c + dir_c[temp.dir] * temp.speed) % N;
				temp.r = (temp.r + dir_r[temp.dir] * temp.speed) % N;
				
				if (temp.r < 0)	temp.r += N;
				if (temp.c < 0)	temp.c += N;
				
				moveBall.push(temp);
			}
		}
	
	while (!moveBall.empty())
	{
		Fireball front = moveBall.front();
		moveBall.pop();
		
		board[front.r][front.c].push(front);
	}
}

void divideFireball(int _r, int _c, int _measure, int _speed, bool _even, bool _odd)
{
	for (int k = 0; k < 4; k++) {
		if (_even && _odd)
			board[_r][_c].push(Fireball(_r, _c, _measure, _speed, k * 2 + 1));
		else
			board[_r][_c].push(Fireball(_r, _c, _measure, _speed, k * 2));
	}
}

void makeOneAndDivide(int _r, int _c)
{
	int ballSize = board[_r][_c].size();

	int new_measure = 0, new_speed = 0;
	bool is_even = false, is_odd = false;
	
	while (!board[_r][_c].empty())
	{
		Fireball ball = board[_r][_c].front();
		board[_r][_c].pop();
		
		new_measure += ball.measure;
		new_speed += ball.speed;
		
		if (ball.dir % 2 == 0) is_even = true;
		else is_odd = true;
	}
	
	new_measure /= 5;
	new_speed /= ballSize;
	
	if (new_measure == 0) return;
	
	divideFireball(_r, _c, new_measure, new_speed, is_even, is_odd);
}


int main()
{
	//input
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
		board[r - 1][c - 1].push(Fireball(r - 1, c - 1, m, s, d));
	}

	while (K-- > 0)
	{
		moveAllFireball();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (board[i][j].size() < 2) continue;
				
				makeOneAndDivide(i, j);
			}
	}

	int sum = 0;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].size() == 0) continue;
			
			while (!board[i][j].empty())
			{
				sum += board[i][j].front().measure;
				board[i][j].pop();
			}
		}

	printf("%d\n", sum);
	return 0;
}