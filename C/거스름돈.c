#include <stdio.h>

int N;
int sol;

int coin[4] = {500, 100, 50, 10};

void solve()
{
	while (N>0)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (N - coin[i] >= 0)
			{
				N -= coin[i];
				sol++;
				break;
			}
			if (N == 0)
				return;
		}
	}
}

int main(void)
{
	// 입력받는 부분
	scanf("%d", &N);

	// 여기서부터 작성
	solve();
	// 출력하는 부분
	printf("%d", sol);

	return 0;
}
