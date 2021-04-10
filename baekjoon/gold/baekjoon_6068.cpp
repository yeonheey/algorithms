#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> work; //t_i, s_i

bool cmp(pair<int, int> a, pair<int, int> b) {
	//먼저 끝내야 하는 일의 순서로 정렬
	return (a.second < b.second);
}

bool can_wakeup(int time) {
	int sum = time;

	for (int i = 0; i < n; i++) {
		if (sum + work[i].first <= work[i].second)
			sum += work[i].first;
		else
			return false;
	}

	return true;
}

int main() {
	//input
	scanf("%d", &n);

	int first, second;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &first, &second);
		work.push_back({ first, second });
	}

	//search
	sort(work.begin(), work.end(), cmp);

	int wake_time = -1;
	int left = 0, right = work[0].second - work[0].first;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (can_wakeup(mid)) {
			left++; wake_time = mid;
		}
		else
			right--;
	}

	printf("%d", wake_time);

	return 0;
}