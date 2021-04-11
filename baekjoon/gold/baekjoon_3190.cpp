#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, l;
char board[101][101]; //'A': apple, 'S': snake
vector<pair<int, char>> change_dir;

//snake�� ��ġ�ϰ� �ִ� ��� ���� ��ǥ
deque<pair<int, int>> snake;

int dir_idx = 0;
int dir_r[4] = { 0, 1, 0, -1 }; //�� �� �� ��
int dir_c[4] = { 1, 0, -1, 0 };

bool cmp(pair<int, char> a, pair<int, char> b) {
	return (a.first < b.first);
}

void input() {
	int temp1, temp2;
	char ch;

	scanf_s("%d", &n);
	scanf_s("%d", &k);

	memset(board, ' ', sizeof(board));
	for (int i = 0; i < k; i++)
	{
		scanf_s("%d %d", &temp1, &temp2);
		board[temp1][temp2] = 'A';
	}

	board[1][1] = 'S';

	scanf_s("%d", &l);
	for (int i = 0; i < l; i++)
	{
		scanf_s("%d %c", &temp1, &ch);
		change_dir.push_back({ temp1, ch });
		getchar();
	}

	sort(change_dir.begin(), change_dir.end(), cmp);

	//snake init
	snake.push_back({ 1,1 });
}

bool is_end(int r, int c) {
	//���� �ε����� ���
	if (r < 1 || c < 1 || r > n || c > n)
		return true;
	//�ڱ� ���� ������ ���
	if (board[r][c] == 'S')
		return true;

	return false;
}

void change_head_direction(int count) {
	for (int i = 0; i < l; i++) {
		if (count == change_dir[i].first) {
			if (change_dir[i].second == 'D') {
				dir_idx++;
				if (dir_idx == 4) dir_idx = 0;
			}
			else {
				dir_idx--;
				if (dir_idx == -1) dir_idx = 3;
			}
		}
		else if (count < change_dir[i].first)
			break;
	}
}

int main() {
	input();

	int time = 0;

	while (true)
	{
		time++;

		//1. �� �Ӹ��� ���� ���� ��ġ Ȯ��
		int next_r = snake.front().first + dir_r[dir_idx];
		int next_c = snake.front().second + dir_c[dir_idx];

		if (is_end(next_r, next_c)) break;

		//2. �Ӹ� ��ġ ����
		char status = board[next_r][next_c];

		snake.push_front({ next_r, next_c });
		board[next_r][next_c] = 'S';

		if (status == ' ') {
			board[snake.back().first][snake.back().second] = ' ';
			snake.pop_back();
		}

		// �̶� change_dir�� ���� �ش� �ʿ� ������ �Ǹ� ����ٲ��ֱ�
		change_head_direction(time);
	}

	printf("%d\n", time);

	return 0;
}