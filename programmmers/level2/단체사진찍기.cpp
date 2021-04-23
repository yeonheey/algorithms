#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
	int count = 0;
	vector<char> pic_line = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

	do {
		bool check = true;

		for (string str : data)
		{
			char friend1 = str[0], friend2 = str[2];
			char oper = str[3];
			int size = (int)(str[4] - '0');

			int f1_idx = find(pic_line.begin(), pic_line.end(), friend1) - pic_line.begin();
			int f2_idx = find(pic_line.begin(), pic_line.end(), friend2) - pic_line.begin();

			if (oper == '=')
			{
				if (abs(f1_idx - f2_idx) - 1 != size)
					check = false;
			}
			else if (oper == '<')
			{
				if (abs(f1_idx - f2_idx) - 1 >= size)
					check = false;
			}
			else //'>'
			{
				if (abs(f1_idx - f2_idx) - 1 <= size)
					check = false;
			}

			if (check == false) break;
		}

		if (check) count++;
	} while (next_permutation(pic_line.begin(), pic_line.end()));

	return count;
}