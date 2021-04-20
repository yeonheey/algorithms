
int solution(int n) {
	int count = 1;

	for (int i = 1; i <= n / 2; i++)
	{
		int sum = i;

		for (int j = i + 1; sum < n && j < n; j++)
			sum += j;

		if (sum == n) count++;
	}

	return count;
}
