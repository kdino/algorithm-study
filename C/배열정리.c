#include <stdio.h>

int X, Y;
int a[1000 + 10][1000 + 10];

void solve()
{
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			if (j == 0)
				continue;
			if (a[i][j - 1] != 0 && a[i][j] != 0)
				a[i][j] = a[i][j - 1] + 1;
		}
	}
}

int main()
{
	int i, j;

	// 입력받는 부분
	scanf("%d %d", &Y, &X);
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	// 여기서부터 작성
	solve();

	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}