#include <bitset>

using namespace std;

const int MAX_SIZE = 20; //max value of N(1,000,000) -> 20 size

int solution_1(int n) {
	int cnt = bitset<20>(n).count();

	while (bitset<20>(++n).count() != cnt);

	return n;
}

int get_binary_one(int n)
{
	int cnt = 0;
	while (n > 0)
	{
		if (n % 2 == 1) cnt++;

		n = n >> 1;
	}

	return cnt;
}

int solution_2(int n) {
	int next_num = 0;
	int one_cnt = get_binary_one(n);

	for (int num = n + 1; ; num++)
		if (get_binary_one(num) == one_cnt)
		{
			next_num = num;
			break;
		}

	return next_num;
}