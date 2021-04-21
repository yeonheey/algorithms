#include <cstdio>

using namespace std;

int N;
char str[500001];
int count = 1;

void count_min(char color)
{
	for (int i = 0; i < N; )
	{
		if (str[i] == color)
		{
			i++; continue;
		}

		while ((i < N) && str[i] != color) i++;

		count++;
	}
}
int main()
{
	scanf("%d", &N);
	scanf("%s", str);

	count_min(str[0]);

	printf("%d\n", count);

	return 0;
}
