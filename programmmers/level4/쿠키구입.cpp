#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> cookie) {
	int max_cookie = 0;

	for (int i = 0; i < cookie.size() - 1; i++) {
		//prefix sum
		int l_idx = i, r_idx = i + 1;
		int l_sum = cookie[l_idx], r_sum = cookie[r_idx];
		
		while (true) {
			if (l_sum == r_sum)
				max_cookie = max(l_sum, max_cookie);

			if (l_sum <= r_sum) {
				if (--l_idx < 0) break;

				l_sum += cookie[l_idx];
			}
			else if (l_sum >= r_sum) {
				if (++r_idx == cookie.size()) break;

				r_sum += cookie[r_idx];
			}
		}
	}

	return max_cookie;
}