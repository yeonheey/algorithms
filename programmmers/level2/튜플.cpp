#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}

bool is_in(vector<int>& dst, int num)
{
	for (int i = 0; i < dst.size(); i++)
		if (num == dst[i])
			return true;

	return false;
}

vector<int> solution(string s) {
	vector<int> tuple_vec;
	vector<vector<int>> element;

	for (int i = 1; i < s.size() - 1; i++)
	{
		if (s[i] == '{')
		{
			vector<int> temp;
			string str = "";

			while (s[++i] != '}')
			{
				if (s[i] == ',')
				{
					temp.push_back(stoi(str));
					str = "";
				}
				else
					str += s[i];
			}

			temp.push_back(stoi(str));
			element.push_back(temp);
		}
	}

	sort(element.begin(), element.end(), compare);

	for (vector<int> ele : element)
		for (int ele_int : ele)
			if (!is_in(tuple_vec, ele_int))
				tuple_vec.push_back(ele_int);

	return tuple_vec;
}