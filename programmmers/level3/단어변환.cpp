#include <string>
#include <vector>
#include <queue>

using namespace std;

bool is_changable(string a, string b)
{
	int cnt = 0;

	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			cnt++;

	if (cnt == 1) return true;

	return false;
}

int solution(string begin, string target, vector<string> words) {
	int count = 0;
	vector<bool> isVisited(words.size(), false);
	queue<pair<int, int>> q; //word_idx, count

	for (int i = 0; i < words.size(); i++)
		if (is_changable(begin, words[i]))
		{
			isVisited[i] = true;
			q.push({ i, 1 });
		}

	while (!q.empty())
	{
		int idx = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (words[idx] == target)
		{
			count = cnt;
			break;
		}

		for (int i = 0; i < words.size(); i++)
		{
			if (isVisited[i]) continue;

			if (is_changable(words[idx], words[i]))
			{
				q.push({ i, cnt + 1 });
				isVisited[i] = true;
			}
		}
	}

	return count;
}