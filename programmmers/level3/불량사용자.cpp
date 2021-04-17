#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> banList;

bool is_changable(string user_id, string ban_id)
{
	if (user_id.size() != ban_id.size()) return false;

	for (int i = 0; i < user_id.size(); i++)
	{
		if (ban_id[i] == '*' || user_id[i] == ban_id[i]) continue;

		return false;
	}

	return true;
}

void findBanList(int user_id_idx, int banSize, const vector<vector<int>>& checkBan, vector<bool>& visited)
{
	if (user_id_idx == banSize)
	{
		string temp = "";
		for (int i = 0; i < visited.size(); i++)
			if (visited[i])
				temp += to_string(i);

		banList.insert(temp);
		return;
	}

	for (int i = 0; i < checkBan[user_id_idx].size(); i++)
	{
		int ban_idx = checkBan[user_id_idx][i];

		if (visited[ban_idx]) continue;

		visited[ban_idx] = true;
		findBanList(user_id_idx + 1, banSize, checkBan, visited);
		visited[ban_idx] = false;
	}


}

int solution(vector<string> user_id, vector<string> banned_id) {
	vector<vector<int>> checkBan(banned_id.size());

	for (int i = 0; i < banned_id.size(); i++)
		for (int j = 0; j < user_id.size(); j++)
			if (is_changable(user_id[j], banned_id[i]))
				checkBan[i].push_back(j);

	vector<bool> visited(user_id.size(), false);
	findBanList(0, banned_id.size(), checkBan, visited);

	return banList.size();
}