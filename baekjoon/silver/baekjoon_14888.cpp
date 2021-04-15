#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> number(11);
vector<char> oper_type = { '+','-','*','/' };
vector<int> opers;

int max_num = -999999999;
int min_num = 999999999;

int calculate(int sum, char oper_type, int num)
{
	if (oper_type == '+')
		sum += num;
	else if (oper_type == '-')
		sum -= num;
	else if (oper_type == '*')
		sum *= num;
	else if (oper_type == '/')
		sum /= num;
	return sum;
}

int main() {
	//input
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &number[i]);
	
	int oper_cnt = 0;
	
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &oper_cnt);

		for (int j = 0; j < oper_cnt; j++)
			opers.push_back(oper_type[i]);
	}
	
	sort(opers.begin(), opers.end());
	
	do {
		int sum = number[0];
		
		for (int i = 0; i < N - 1; i++)
			sum = calculate(sum, opers[i], number[i + 1]);
		
		max_num = max(max_num, sum);
		min_num = min(min_num, sum);

	} while (next_permutation(opers.begin(), opers.end()));
	
	printf("%d\n%d\n", max_num, min_num);
	
	return 0;
}
