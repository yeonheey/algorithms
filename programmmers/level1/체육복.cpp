#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int count = 0;
	vector<int> student(n, 1);

	for (int r : reserve)
		++student[r - 1];

	for (int l : lost)
		--student[l - 1];

	for (int i = 0; i < n; i++)
	{
		if (0 == student[i])
		{
			++count;

			if (i < (n - 1) && student[i + 1] > 1)
				--student[i + 1];
			else if (i > 0 && student[i - 1] > 1)
				--student[i - 1];
			else
				--count;
		}
		else
			++count;
	}

	return count;
}