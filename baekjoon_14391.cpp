//종이 조각
#include <stdio.h>
#include <algorithm>
using namespace std;
int board[5][5];
int max_sum = 0;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &board[i][j]);
	for (int loc = 0; loc < (1 << (m * n)); loc++) {
		int sum = 0;
		//horizon(0일때 가로)
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < m; j++) {
				int k = i * m + j;
				if ((loc & (1 << k)) == 0)
					temp = temp * 10 + board[i][j];
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}
		//vertical(1일때 세로)
		for (int j = 0; j < m; j++) {
			int temp = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;
				if ((loc & (1 << k)) != 0)
					temp = temp * 10 + board[i][j];
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}
		max_sum = max(max_sum, sum);
	}
	printf("%d\n", max_sum);
	return 0;
}