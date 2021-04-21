#include <cstdio>
#include <algorithm>

using namespace std;

const int SIZE = 1000001;
int N, K;
long long ice[SIZE];
long long dp_ice[SIZE];

int main()
{
	long long max_count = 0;
	scanf("%d %d", &N, &K);

	for (int i = 0, x, g; i < N; i++)
	{
		scanf("%d %d", &g, &x);
		ice[x] = g;
	}

	dp_ice[0] = ice[0];
	for (int i = 1; i < SIZE; i++)
		dp_ice[i] = dp_ice[i - 1] + ice[i];

	if (K < SIZE)
	{
		for (int i = 0; i < SIZE; i++)
			if ((i + K) < SIZE && (i - K) > 0)
				max_count = max(max_count, dp_ice[i + K] - dp_ice[i - K - 1]);
	}
	else
		max_count = dp_ice[SIZE - 1];

	printf("%ld\n", max_count);

	return 0;
}