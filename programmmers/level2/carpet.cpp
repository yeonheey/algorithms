#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> size(2, 0);

	for (int h = 1; h <= yellow; h++)
	{
		int w = yellow / h;

		if (h <= w && 0 == yellow % h)
			if (2 * h + 2 * w + 4 == brown)
			{
				size[0] = w + 2;
				size[1] = h + 2;
				break;
			}
	}

	return size;
}